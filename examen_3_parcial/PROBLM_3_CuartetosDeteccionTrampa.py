

#  Sistema de detección de trampas en Cuartetos
NUM_JUG = 4
NUM_SETS = 8
CARTAS_POR_SET = 4
TOTAL_CARTAS = NUM_SETS * CARTAS_POR_SET


def crear_cartas():
    return list(range(TOTAL_CARTAS))


def set_de_carta(c):
    return c // CARTAS_POR_SET


def run():
    print(" Sistema de Detección de Trampas en Cuartetos \n")
    print("Formato de acciones permitidas:")
    print("  pide A B C")
    print("  entrega B A C")
    print("  niega B A C")
    print("  cuarteto A S")

    n = int(input("Cantidad de acciones a registrar: "))

    posibles = [set(crear_cartas()) for _ in range(NUM_JUG)]
    dueño = [-1] * TOTAL_CARTAS  # -1 = desconocido

    def asegurar(j, c):
        if dueño[c] != -1 and dueño[c] != j:
            return False
        dueño[c] = j
        for k in range(NUM_JUG):
            if k != j and c in posibles[k]:
                posibles[k].discard(c)
        if c not in posibles[j]:
            return False
        return True

    def descartar(j, c):
        if dueño[c] == j:
            return False
        if c in posibles[j]:
            posibles[j].discard(c)

        candidatos = [x for x in range(NUM_JUG) if c in posibles[x]]
        if len(candidatos) == 0:
            return False
        if len(candidatos) == 1:
            return asegurar(candidatos[0], c)
        return True

    # Procesar acciones una por una
    for i in range(1, n + 1):
        print(f"\nAcción #{i}:")
        partes = input("Ingresa acción: ").strip().split()

        if len(partes) == 0:
            print("Formato inválido")
            return

        if partes[0] == "pide":
            if len(partes) != 4:
                print("Formato incorrecto en acción pide.")
                return
            A = int(partes[1])
            B = int(partes[2])
            C = int(partes[3])
            s = set_de_carta(C)

            tiene_alguna = any(
                c in posibles[A] for c in range(s * 4, s * 4 + 4)
            )

            if not tiene_alguna:
                print("no", i)
                return

        elif partes[0] == "entrega":
            if len(partes) != 4:
                print("Formato incorrecto en acción entrega.")
                return
            B = int(partes[1])
            A = int(partes[2])
            C = int(partes[3])

            if not asegurar(B, C):
                print("no", i)
                return

            if not asegurar(A, C):
                print("no", i)
                return

        elif partes[0] == "niega":
            if len(partes) != 4:
                print("Formato incorrecto en acción niega.")
                return
            B = int(partes[1])
            A = int(partes[2])
            C = int(partes[3])

            if not descartar(B, C):
                print("no", i)
                return

        elif partes[0] == "cuarteto":
            if len(partes) != 3:
                print("Formato incorrecto en acción cuarteto.")
                return
            A = int(partes[1])
            S = int(partes[2])

            for c in range(S * 4, S * 4 + 4):
                if not asegurar(A, c):
                    print("no", i)
                    return

        else:
            print("no", i)
            return

    print("\nResultado final: si (no se detectaron trampas)")


if __name__ == "__main__":
    run()
