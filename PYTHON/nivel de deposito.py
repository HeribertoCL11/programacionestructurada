nivel = float(input("Ingrese nivel del depósito (%): "))

if nivel < 10:
    print("Depósito VACÍO")
elif nivel <= 90:
    print("Niveles NORMALES")
else:
    print("Posible DESBORDAMIENTO")
