def matches(mosaic, pattern, r, c, PR, PC):
    for i in range(PR):
        for j in range(PC):
            if pattern[i][j] != 0 and pattern[i][j] != mosaic[r+i][c+j]:
                return False
    return True


def find_pattern(mosaic, pattern):
    R = len(mosaic)
    C = len(mosaic[0])
    PR = len(pattern)
    PC = len(pattern[0])

    results = []

    # Recorremos todas las posiciones posibles donde cabe el patrón
    for r in range(R - PR + 1):
        for c in range(C - PC + 1):
            if matches(mosaic, pattern, r, c, PR, PC):
                results.append((r, c))

    return results


def main():
    print(" BÚSQUEDA DE MOSAICO ")
    
    # Entrada del patrón
    print("\nIngresa dimensiones del patrón (filas columnas):")
    PR, PC = map(int, input().split())

    print("Ingresa el patrón (0 = vacío):")
    pattern = []
    for _ in range(PR):
        fila = list(map(int, input().split()))
        pattern.append(fila)

    # Entrada del mosaico
    print("\nIngresa dimensiones del mosaico (filas columnas):")
    R, C = map(int, input().split())

    print("Ingresa el mosaico:")
    mosaic = []
    for _ in range(R):
        fila = list(map(int, input().split()))
        mosaic.append(fila)

    # Procesar
    results = find_pattern(mosaic, pattern)

    # Salida
    print("\n RESULTADOS ")
    print(len(results))
    for r, c in results:
        print(r, c)


if __name__ == "__main__":
    main()
