def color_to_num(c):
    return {"R": 0, "G": 1, "B": 2}[c]

def mod_inv_3(x):
    # En Z/3Z, la inversa de 1 es 1 y la de 2 es 2 (porque 2*2 = 4 = 1 mod 3)
    if x == 1:
        return 1
    if x == 2:
        return 2
    return None  # 0 no tiene inversa


def gauss_jordan_mod3(A, b):
    """
    Resuelve A x = b en Z/3Z usando Gauss-Jordan.
    Devuelve (sol, libre):
        sol = solución particular (si existe)
        libre = lista de índices de variables libres
    Si no hay solución, devuelve (None, None)
    """
    n = len(A)       # ecuaciones (luces)
    m = len(A[0])    # variables (botones)

    row = 0
    pivot_col = [-1] * n

    for col in range(m):
        # Encontrar fila pivote
        pivot = -1
        for r in range(row, n):
            if A[r][col] != 0:
                pivot = r
                break

        if pivot == -1:
            continue

        # Intercambiar fila actual con pivote
        A[row], A[pivot] = A[pivot], A[row]
        b[row], b[pivot] = b[pivot], b[row]

        # Normalizar pivote a 1
        inv = mod_inv_3(A[row][col])
        A[row] = [(x * inv) % 3 for x in A[row]]
        b[row] = (b[row] * inv) % 3

        # Eliminar en otras filas
        for r in range(n):
            if r != row and A[r][col] != 0:
                factor = A[r][col]
                A[r] = [(A[r][c] - factor * A[row][c]) % 3 for c in range(m)]
                b[r] = (b[r] - factor * b[row]) % 3

        pivot_col[row] = col
        row += 1
        if row == n:
            break

    # Revisar inconsistencia: 0 = b
    for r in range(n):
        if all(A[r][c] == 0 for c in range(m)) and b[r] != 0:
            return None, None

    # Variables libres
    pivot_set = set(pc for pc in pivot_col if pc != -1)
    libres = [i for i in range(m) if i not in pivot_set]

    # Construir solución particular
    x = [0] * m
    for r in range(n):
        c = pivot_col[r]
        if c != -1:
            # valor ya está determinado por la fila
            x[c] = b[r]

    return x, libres


def enumerate_min_solution(sol, free_vars):
    """
    Busca la solución con menor suma (número de pulsaciones).
    Para cada variable libre, se prueban 0,1,2.
    """
    import itertools

    if not free_vars:
        return sum(sol), sol

    best_cost = float('inf')
    best_sol = None

    for combo in itertools.product([0,1,2], repeat=len(free_vars)):
        candidate = sol[:]
        for fv, val in zip(free_vars, combo):
            candidate[fv] = val % 3

        cost = sum(candidate)
        if cost < best_cost:
            best_cost = cost
            best_sol = candidate

    return best_cost, best_sol


def main():
    print("=== TURNING RED - ENCENDER TODAS LAS LUCES EN ROJO ===\n")

    # Leer número de luces y botones
    l = int(input("Número de luces: "))
    b = int(input("Número de botones: "))

    # Estado inicial
    estado = input("Estado inicial (cadena de R/G/B): ").strip().upper()
    init = [color_to_num(c) for c in estado]

    # Matriz A[l][b]
    A = [[0]*b for _ in range(l)]

    print("\nPara cada botón, ingresa cuántas luces controla y sus índices (0-based).")
    print("Ejemplo: 3 0 2 5  -> controla luces 0, 2 y 5")

    for i in range(b):
        data = list(map(int, input(f"Botón {i}: ").split()))
        k = data[0]
        luces = data[1:]

        for luz in luces:
            A[luz][i] = 1  # presionar botón suma +1 mod 3 a esa luz

    # Queremos resolver:
    # A * x = (-init) mod 3   → porque queremos final = 0 (rojo)
    bvec = [(-v) % 3 for v in init]

    # Resolver el sistema
    sol, libres = gauss_jordan_mod3(A, bvec)

    if sol is None:
        print("\nimpossible")
        return

    # Buscar la solución con mínima suma
    min_cost, best_sol = enumerate_min_solution(sol, libres)

    print("\n RESULTADO ")
    print("Mínimo número de pulsaciones:", min_cost)


if __name__ == "__main__":
    main()