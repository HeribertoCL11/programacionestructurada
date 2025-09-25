voltaje = float(input("Ingrese el voltaje: "))

if voltaje < 220 or voltaje > 240:
    print("alarma activada")
else:
    print("voltaje dentro del rango")
