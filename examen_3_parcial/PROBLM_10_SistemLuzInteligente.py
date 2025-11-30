def gauss_jordan_gf2(A, b):
    
    n = len(A)       # luces
    m = len(A[0])    # interruptores

    row = 0
    pivot_col = [-1] * n

    for col in range(m):
        # Encontrar fila pivote
        pivot = -1
        for r in range(row, n):
            if A[r][col] == 1:
                pivot = r
                break
        if pivot == -1:
            continue

        # Intercambio filas
        A[row], A[pivot] = A[pivot], A[row]
        b[row], b[pivot] = b[pivot], b[row]

        # Eliminar en otras filas
        for r in range(n):
            if r != row and A[r][col] == 1:
                A[r] = [(A[r][c] ^ A[row][c]) for c in range(m)]
                b[r] = b[r] ^ b[row]

        pivot_col[row] = col
        row += 1
        if row == n:
            break

    # Revisión de inconsistencias
    for r in range(n):
        if all(A[r][c] == 0 for c in range(m)) and b[r] == 1:
            return None, None

    # Variables libres
    pivot_set = set(pc for pc in pivot_col if pc != -1)
    free_vars = [i for i in range(m) if i not in pivot_set]

    # Solución particular
    x = [0] * m
    for r in range(n):
        c = pivot_col[r]
        if c != -1:
            x[c] = b[r]

    return x, free_vars


def best_solution_gf2(sol, free_vars):
    """
    Intenta todas las combinaciones de las variables libres (0 o 1).
    Devuelve la solución de menor peso (menor número de 1s).
    """
    import itertools

    if not free_vars:
        return sum(sol), sol

    best_weight = float('inf')
    best_sol = None

    for combo in itertools.product([0,1], repeat=len(free_vars)):
        candidate = sol[:]
        for idx, val in zip(free_vars, combo):
            candidate[idx] = val

        weight = sum(candidate)
        if weight < best_weight:
            best_weight = weight
            best_sol = candidate

    return best_weight, best_sol


def main():
    print(" SISTEMA DE LUCES INTELIGENTE (GF(2)) \n")

    n = int(input("Número de luces: "))
    m = int(input("Número de interruptores: "))

    print("\nEstado inicial (cadena de 0 y 1):")
    init = list(map(int, list(input().strip())))

    print("Estado deseado (cadena de 0 y 1):")
    target = list(map(int, list(input().strip())))

    if len(init) != n or len(target) != n:
        print("\nError: longitud incorrecta.")
        return

    # Matriz A: n x m
    A = [[0]*m for _ in range(n)]

    print("\nPara cada interruptor, ingresa:")
    print("k i1 i2 ... ik   donde i_j son índices de luces (0-based)")

    for j in range(m):
        data = list(map(int, input(f"Interruptor {j}: ").split()))
        k = data[0]
        luces = data[1:]
        for luz in luces:
            A[luz][j] = 1

    # Vector b = init XOR target
    b = [(init[i] ^ target[i]) for i in range(n)]

    # Resolver sistema
    sol, free_vars = gauss_jordan_gf2(A, b)

    if sol is None:
        print("\nimpossible")
        return

    # Elegir solución mínima
    weight, best = best_solution_gf2(sol, free_vars)

    print("\n=== RESULTADO ===")
    print("Número mínimo de interruptores a activar:", weight)

    print("\n¿Mostrar secuencia de interruptores? (s/n)")
    ans = input().strip().lower()
    if ans == "s":
        seq = [i for i in range(m) if best[i] == 1]
        print("\nInterruptores a activar:", seq)


if __name__ == "__main__":
    main()
