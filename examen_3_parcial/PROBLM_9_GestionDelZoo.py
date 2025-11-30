from collections import defaultdict, deque

def bfs_component(start, graph, comp_id, comp):
    queue = deque([start])
    comp[start] = comp_id
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if comp[v] == -1:
                comp[v] = comp_id
                queue.append(v)

def main():
    print(" GESTIÓN DEL ZOO - Verificar si la reconfiguración es posible \n")

    # Leer recintos y túneles
    n = int(input("Número de recintos: "))
    m = int(input("Número de túneles: "))

    print("\nIntroduce los animales actuales (uno por recinto):")
    current = input("Animales actuales (ej: TIGRE LEON OSO ...): ").split()

    print("\nIntroduce los animales deseados (uno por recinto):")
    target = input("Animales deseados (misma cantidad): ").split()

    # Verificar tamaños
    if len(current) != n or len(target) != n:
        print("\nimpossible")
        return

    graph = [[] for _ in range(n)]

    print("\nIntroduce los túneles (u v) con índices 0-based:")
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    # misma multiset de animales
    count_current = defaultdict(int)
    count_target = defaultdict(int)

    for a in current:
        count_current[a] += 1
    for a in target:
        count_target[a] += 1

    if count_current != count_target:
        print("\nimpossible")
        return

    #  calcular componentes conectados
    comp = [-1] * n
    comp_id = 0
    for i in range(n):
        if comp[i] == -1:
            bfs_component(i, graph, comp_id, comp)
            comp_id += 1

    # --- Paso 3: para cada animal, comparar posiciones actuales vs deseadas ---
    positions_current = defaultdict(list)
    positions_target = defaultdict(list)

    for i in range(n):
        positions_current[current[i]].append(i)
        positions_target[target[i]].append(i)

    # Verificación de componentes
    for animal in positions_current:
        cur = positions_current[animal]
        tar = positions_target[animal]

        # Ordenamos para emparejarlos por cantidad
        cur.sort()
        tar.sort()

        # Cada movimiento origen -> destino debe estar en la misma componente
        for c, t in zip(cur, tar):
            if comp[c] != comp[t]:
                print("\nimpossible")
                return

    print("\npossible")


if __name__ == "__main__":
    main()
