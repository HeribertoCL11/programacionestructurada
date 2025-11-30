#define librerias
from fractions import Fraction
import itertools

#resuelve un sistema de 3 ecuaciones lineales con 3 incógnitas usando eliminación gaussiana
def solve_3x3(A, B):
    M = [[Fraction(A[i][j]) for j in range(3)] + [Fraction(B[i])] for i in range(3)]
#aplicacion eliminacion gaussiana
    for col in range(3):
        pivot = None
        #buscar fila con pivote
        for r in range(col, 3):
            if M[r][col] != 0:
                pivot = r
                break
        if pivot is None:
            return None
#intercambiar filas si es necesario
        if pivot != col:
            M[col], M[pivot] = M[pivot], M[col]
#define la fila para que el pivote sea 1
        p = M[col][col]
        M[col] = [v / p for v in M[col]]

        for r in range(3):
            if r != col:
                #elimina las demas filas
                factor = M[r][col]
                M[r] = [M[r][c] - factor * M[col][c] for c in range(4)]
#devuelve la solucion exacta
    return M[0][3], M[1][3], M[2][3]
#busca la respuesta falsa
def solve_with_one_lie(questions, answers):
#itera sobre cada pregunta asumiendo que es la mentira
    for lie in range(5):

        eqs = []
        vals = []

        for i in range(5):
            #construye un conjunton de 4 ecuaciones verdaderas
            if i != lie:
                eqs.append(questions[i])
                vals.append(Fraction(answers[i]))
#prueba todas las combinaciones de 3 ecuaciones de las 4 verdaderas
        for combo in itertools.combinations(range(4), 3):
            A = [eqs[i] for i in combo]
            B = [vals[i] for i in combo]
#resuelve cada sistema de 3 ecuaciones
            sol = solve_3x3(A, B)
            if sol is None:
                continue

            x, y, z = sol
#verifica que la solucion sea
            if x < 0 or y < 0 or z < 0:
                continue
            if x != int(x) or y != int(y) or z != int(z):
                continue

            xi, yi, zi = int(x), int(y), int(z)

            ok = True
            for i in range(5):
                if i == lie:
                    continue
                a, b, c = questions[i]
                #verifica si la solucion cumple con las ecuaciones exepto la mentira
                if a * xi + b * yi + c * zi != answers[i]: 
                    ok = False
                    break

            if ok:
                return xi, yi, zi, lie

    return None



questions = []
answers = []

print("Ingresa 5 preguntas del tipo: a b c, del 1 al 10")
for i in range(5):
    #lee las preguntas y respuestas
    a, b, c = map(int, input(f"Pregunta {i+1} (a b c): ").split())
    questions.append((a, b, c))

print("\nIngresa las respuestas de la Esfinge:")
for i in range(5):
    r = int(input(f"Respuesta {i+1}: "))
    answers.append(r)

sol = solve_with_one_lie(questions, answers)

if sol is None:
    print("No se pudo determinar una solución consistente con una sola mentira.")
else:
    axex, basiliso, centauro, lie_index = sol
    #muestra la solucion
    print(f"Axex = {axex} patas")
    print(f"Basiliso = {basiliso} patas")
    print(f"Centauro = {centauro} patas")
    print(f"La mentira está en la pregunta #{lie_index + 1}")
