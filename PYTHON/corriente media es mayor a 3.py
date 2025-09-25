corriente = float(input("Ingrese corriente (A): "))
voltaje = float(input("Ingrese voltaje (V): "))

if corriente > 3 and voltaje < 1:
    print("Alarma de CORTOCIRCUITO")
else:
    print("Sistema en monitoreo...")
