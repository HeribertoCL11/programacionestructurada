
import sys
sys.setrecursionlimit(10**7)
# Lectura interactiva de enteros

def read_ints_prompt(prompt=None):
    while True:
        try:
            s = input(prompt) if prompt is not None else input()
            parts = list(map(int, s.strip().split()))
            if len(parts) == 0:
                print("Entrada vacía, intenta de nuevo.")
                continue
            return parts
        except ValueError:
            print("Formato inválido. Ingresa números separados por espacios.")


# Inicio interactivo

print(" Programa interactivo: árbol, distancias, diámetro y queries \n")

# Leer n, q
while True:
    vals = read_ints_prompt("Ingresa n q (n = número de nodos, q = número de consultas): ")
    if len(vals) >= 2:
        n, q = vals[0], vals[1]
        break
    else:
        print("Debes ingresar dos enteros: n y q.")

# Construir lista de adyacencia
adj = [[] for _ in range(n)]
total_weight = 0
print(f"\nAhora ingresa {n-1} aristas en formato: u v w (1-indexed).")

for i in range(n - 1):
    while True:
        parts = read_ints_prompt(f"Arista {i+1}/{n-1}: ")
        if len(parts) >= 3:
            u, v, w = parts[0], parts[1], parts[2]
            u -= 1; v -= 1
            if not (0 <= u < n and 0 <= v < n):
                print("Índices de nodo fuera de rango, inténtalo de nuevo.")
                continue
            adj[u].append((v, w))
            adj[v].append((u, w))
            total_weight += w
            break
        else:
            print("Debes dar 3 números: u v w.")
# DFS para distancias y padres

LOG = max(1, (n-1).bit_length() + 1)  # suficiente para n
parent = [[-1]*n for _ in range(LOG)]
depth = [0]*n
dist = [0]*n

def dfs(u, p):
    for v, w in adj[u]:
        if v == p:
            continue
        depth[v] = depth[u] + 1
        dist[v] = dist[u] + w
        parent[0][v] = u
        dfs(v, u)

# Tomamos nodo 0 como raíz
dfs(0, -1)

# Llenar tabla binaria de ancestros
for k in range(1, LOG):
    for i in range(n):
        if parent[k-1][i] != -1:
            parent[k][i] = parent[k-1][parent[k-1][i]]

# ------------------------------
# LCA y distancia entre nodos
# ------------------------------
def lca(a, b):
    if a == -1 or b == -1:
        return -1
    if depth[a] < depth[b]:
        a, b = b, a
    diff = depth[a] - depth[b]
    k = 0
    while diff:
        if diff & 1:
            a = parent[k][a]
        diff >>= 1
        k += 1
    if a == b:
        return a
    for k in range(LOG-1, -1, -1):
        if parent[k][a] != parent[k][b]:
            a = parent[k][a]
            b = parent[k][b]
    return parent[0][a]

def dist_nodes(a, b):
    c = lca(a, b)
    if c == -1:
        return 10**30
    return dist[a] + dist[b] - 2*dist[c]

# Método: dos BFS/DFS: hallar un extremo 'a' desde 0 y luego extremo 'b' desde 'a'.
# Reutilizaremos dist_nodes que depende de la raíz 0, pero esto está bien porque
# dist[] y lca funcionan para cualquier par.
def farthest(start):
    best = (0, start)
    stack = [(start, -1)]
    visited = [False]*n
    visited[start] = True
    while stack:
        u, p = stack.pop()
        for v, _ in adj[u]:
            if visited[v]:
                continue
            visited[v] = True
            d = dist_nodes(start, v)
            if d > best[0]:
                best = (d, v)
            stack.append((v, u))
    return best

_, a = farthest(0)
d, b = farthest(a)
diameter = d

min_cover_all = 2 * total_weight - diameter

# ------------------------------
# Función auxiliar: comprobar si x está en camino a-b
# ------------------------------
def is_on_path(x, a, b):
    return dist_nodes(a, b) == dist_nodes(a, x) + dist_nodes(x, b)

# ------------------------------
# Procesar queries (interactivo)
# ------------------------------
print("\nAhora ingresa las consultas. Formato por consulta: S L T (1-indexed).")
print("Reglas: si existe contradicción según la lógica del problema, se imprime 'impossible',")
print("sino se imprime el valor mínimo de tiempo para recorrer todo el árbol (min_cover_all).")

for qi in range(1, q+1):
    while True:
        parts = read_ints_prompt(f"Consulta {qi}/{q}: ")
        if len(parts) >= 3:
            S, L, T = parts[0]-1, parts[1]-1, parts[2]-1
            if not (0 <= S < n and 0 <= L < n and 0 <= T < n):
                print("Índices fuera de rango, inténtalo de nuevo.")
                continue
            break
        else:
            print("Debes ingresar 3 enteros: S L T.")

    # 1) Si en la ruta S -> L aparece T antes de llegar a L -> impossible
    if is_on_path(T, S, L):
        print("impossible")
        continue

    # 2) Si L está en el camino S–T y T está "antes" que L en dicho camino -> impossible
    if is_on_path(L, S, T):
        # Si la distancia S->T es menor que S->L entonces T está antes que L en el camino desde S
        if dist_nodes(S, T) < dist_nodes(S, L):
            print("impossible")
            continue

    # Si pasa las restricciones:
    print(min_cover_all)

print("\nFin de la ejecución.")
