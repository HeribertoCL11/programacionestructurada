
def query(node, out_id, k, nodes, m):
    """Resuelve la consulta (node, out_id, k) hacia atrás."""
    while True:
        if node == -1:
            return k if 1 <= k <= m else None

        t = nodes[node]["type"]

        if t == "split":
            parent = nodes[node]["parent"]
            if out_id == 1:
                k = 2*k - 1
            else:
                k = 2*k
            node = parent
            out_id = 1

        else:  # merge
            p1, p2 = nodes[node]["parents"]
            if k % 2 == 1:
                k = (k + 1)//2
                node = p1
            else:
                k = k//2
                node = p2
            out_id = 1

m, n, q = map(int, input("Ingresa m n q: ").split())

nodes = [{} for _ in range(n)]

print("Ingresa cada nodo:")
print("   split X     (significa split in=X)")
print("   merge X Y   (merge con entradas X y Y)")
print("Usa 0 para origen.\n")

for i in range(n):
    datos = input(f"Nodo {i+1}: ").split()
    tipo = datos[0]
    nodes[i]["type"] = tipo

    if tipo == "split":
        x = int(datos[1]) - 1
        nodes[i]["parent"] = x
    else:
        x = int(datos[1]) - 1
        y = int(datos[2]) - 1
        nodes[i]["parents"] = (x, y)

print("\nIngresa las consultas: nodo salida k\n")

for _ in range(q):
    a, s, k = map(int, input().split())
    a -= 1

    ans = query(a, s, k, nodes, m)

    if ans is None:
        print("none")
    else:
        print(ans)
