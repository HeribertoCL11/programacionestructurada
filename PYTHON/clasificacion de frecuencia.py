f = float(input("Ingrese la frecuencia (Hz): "))

if f < 20:
    print("Sub-sonido")
elif f <= 20000:
    print("Sonido")
else:
    print("Ultrasonido")
