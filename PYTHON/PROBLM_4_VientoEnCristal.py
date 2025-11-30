
def print_grid(grid, dx, dy):
    """Imprime una grilla usando * para molécula y . para vacío."""
    for y in range(dy):
        row = ''.join('*' if grid[y][x] == 1 else '.' for x in range(dx))
        print(row)


def main():
    print("=== Problema 4: Viento en Cristal (Crystal Crosswind) ===\n")

    # Leer dimensiones del cristal
    dx = int(input("Ingresa ancho (dx): "))
    dy = int(input("Ingresa alto  (dy): "))
    k = int(input("Número de vientos/observaciones: "))

    print("\nCada viento debe ingresarse así:")
    print("  wx wy t")
    print("donde t = número de observaciones de límites.")
    print("Luego se ingresan t líneas del tipo:")
    print("  x y   (punto donde hay molécula, pero NO en (x+wx, y+wy))\n")

    # -1 = desconocido, 0 = vacío, 1 = molécula
    state = [[-1 for _ in range(dx)] for __ in range(dy)]

    def in_bounds(x, y):
        return 0 <= x < dx and 0 <= y < dy

    def set_cell(x, y, val):
        """
        Asigna valor a una celda.
        Return False si hay contradicción.
        """
        if not in_bounds(x, y):
            # Si intentan poner molécula fuera de los límites → imposible
            if val == 1:
                return False
            return True

        cur = state[y][x]
        if cur == -1:
            state[y][x] = val
            return True
        return cur == val

    for i in range(1, k + 1):
        print(f"\n--- Viento #{i} ---")
        wx, wy, t = map(int, input("Ingresa wx wy t: ").split())

        for j in range(1, t + 1):
            x, y = map(int, input(f"  Observación {j}/{t} (x y): ").split())

            # regla: hay molécula en (x,y)
            if not set_cell(x, y, 1):
                print("\n Contradicción: no es posible una configuración que cumpla todo.")
                return

            # regla: NO hay molécula en (x+wx, y+wy)
            nx, ny = x + wx, y + wy
            if not set_cell(nx, ny, 0):
                print("\n Contradicción: no es posible una configuración que cumpla todo.")
                return

    print("\n Todas las observaciones son consistentes.\n")

    # Configuración mínima: todo lo desconocido → vacío (0)
    min_grid = [
        [(0 if state[y][x] == -1 else state[y][x]) for x in range(dx)]
        for y in range(dy)
    ]

    # Configuración máxima: todo lo desconocido → molécula (1)
    max_grid = [
        [(1 if state[y][x] == -1 else state[y][x]) for x in range(dx)]
        for y in range(dy)
    ]

    print(" Configuración MÍNIMA ")
    print_grid(min_grid, dx, dy)

    print("\n Configuración MÁXIMA ")
    print_grid(max_grid, dx, dy)


if __name__ == "__main__":
    main()
