

#  Función para calcular probabilidad A > B
def prob_win(A, B):
    wins = 0
    for a in A:
        for b in B:
            if a > b:
                wins += 1
    return wins / (len(A) * len(B))

#  Función principal
def main():
    print(" Cálculo de probabilidades A > B\n")

    # Leer D1
    n1 = int(input("Cantidad de valores del dado D1: "))
    D1 = []
    print("valores de D1:")
    for _ in range(n1):
        D1.append(int(input("> ")))

    # Leer D2
    n2 = int(input("\ncantidad de valores del dado D2: "))
    D2 = []
    print("valores de D2:")
    for _ in range(n2):
        D2.append(int(input("> ")))

    # Posibles valores para D3
    candidates = sorted(set(D1 + D2))

    best_vs_D1 = 0.0
    worst_vs_D2 = 1.0

    # Probar todas las opciones posibles para D3 como un dado de una sola cara
    for x in candidates:
        D3 = [x]

        p31 = prob_win(D3, D1)  # probabilidad D3 > D1
        p32 = prob_win(D3, D2)  # probabilidad D3 > D2

        best_vs_D1 = max(best_vs_D1, p31)
        worst_vs_D2 = min(worst_vs_D2, p32)

    print("\n=== RESULTADOS ===")
    print(f"Peor probabilidad contra D2: {worst_vs_D2:.9f}")
    print(f"Mejor probabilidad contra D1: {best_vs_D1:.9f}")


# Ejecutar
if __name__ == "__main__":
    main()

