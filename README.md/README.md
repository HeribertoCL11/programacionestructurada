Problemas de probabilidades y dados

Los resolví entendiendo que cada dado representa un conjunto finito de valores posibles.
La probabilidad de que uno gane al otro se obtiene comparando todas las combinaciones entre ambos.
Para un tercer dado, basta evaluar posibles valores candidatos y medir cómo afectan las probabilidades.
El enfoque consiste en analizar comparaciones directas y escoger los valores que maximizan o minimizan el resultado según corresponda.

 2. Sistema de detección de trampas en juegos

El problema se basa en mantener, para cada jugador, un conjunto de cartas que aún podría tener según la información conocida.
Cada acción del juego elimina posibilidades o confirma certezas.
Cuando un jugador pide una carta, entrega una carta, niega una carta o anuncia un conjunto completo, cada una de estas acciones impone restricciones que reducen las posibilidades.
El método consiste en descartar situaciones imposibles y validar que ninguna acción contradiga información previa.
Si aparece una contradicción lógica, se detecta la trampa; si no, el conjunto de posibilidades sigue siendo coherente.
 3. Problema del viento en el cristal

El razonamiento se basa en interpretar cada observación como dos hechos:
una celda contiene molécula y la celda ubicada en la dirección del viento no la contiene.
El análisis consiste en registrar esta información en una cuadrícula parcialmente conocida.
Una vez integradas todas las restricciones, las celdas sin información se pueden completar con la opción mínima (todas vacías) o máxima (todas llenas) que siga siendo coherente.
Con esto se construyen dos configuraciones extremas compatibles con las condiciones.

 4.Problema del árbol, distancias y recorridos obligados

Se analizó la estructura como un árbol ponderado donde las distancias se calculan de acuerdo con los pesos de las aristas.
Para determinar relaciones entre nodos como ancestros, rutas o intersecciones obligadas, se utiliza la propiedad de que en un árbol existe un único camino entre dos puntos.
El diámetro del árbol determina cuánto tiempo puede ahorrarse en un recorrido óptimo.
La lógica consiste en verificar si un nodo está forzado a aparecer antes que otro en un camino, lo cual invalida ciertas rutas.
Si aparece una condición inevitable en la cual un punto prohibido debe visitarse antes que un punto permitido, se declara imposible.

 5. Problema de la red de splits y merges

El razonamiento consiste en rastrear un elemento solicitado hacia atrás a través de la red de nodos.
Un split distribuye elementos alternando posiciones, y un merge los combina también alternando posiciones.
Para saber de dónde proviene un elemento específico en una salida, se recorre la red en sentido inverso, ajustando la posición deseada según las reglas de intercalado.
Cuando se llega al origen, se identifica el elemento real.
Si la posición requerida queda fuera del rango o no corresponde a un origen válido, se declara inexistente.

 7.Búsqueda de Mosaicos

La idea consiste en revisar todas las posiciones en el mosaico donde el motivo podría encajar.
Para cada posición posible, se compara celda por celda entre el motivo y el mosaico.
Las celdas del motivo que son vacías no imponen requisitos, mientras que las que tienen color deben coincidir exactamente con el mosaico.
Si todas las celdas obligatorias coinciden, se registra esa posición como válida.

 8. Encender Luces en Rojo (Turning Red)

Las luces cambian de estado siguiendo ciclos fijos y cada botón afecta a un conjunto particular de luces.
El comportamiento de cada luz puede representarse mediante operaciones de suma modular porque cada ciclo es repetitivo.
El sistema completo se formula como un conjunto de ecuaciones donde los botones representan variables que alteran estados de luces.
Como el estado solo depende de cuántas veces se presiona cada botón, y no del orden, el problema se convierte en resolver un sistema lineal en un espacio donde solo importan valores modulares.
Una vez resuelto el sistema matemático, se identifica la combinación con la menor cantidad de botones activados que cumple los requisitos de llegar al estado final.
Si el sistema no admite solución, la transformación es imposible.

9. Gestión del Zoo

Los animales deben reorganizarse entre recintos conectados por túneles.
El movimiento simultáneo impone restricciones que impiden que se crucen dentro de un túnel, pero como todos se mueven al mismo tiempo, lo que realmente importa es si cada animal puede alcanzar el recinto donde debe quedar.
Para verificarlo, se comparan las posiciones iniciales y finales de cada tipo de animal, verificando que cada desplazamiento necesario ocurra dentro de una región del zoo que esté completamente conectada.
Además, debe existir el mismo número de animales de cada tipo tanto al inicio como al final.
Si cada animal puede viajar dentro de su componente conectada hacia una posición final del mismo tipo, la reorganización es posible; si no, es imposible.

 10.Sistema de Luces Inteligente

Las luces pueden conmutarse por interruptores, y cada pulsación corresponde a una operación reversible que altera ciertos elementos.
Como cada operación cambia únicamente el estado de las luces asociadas a un interruptor, el efecto total de una secuencia de pulsaciones se puede representar como una suma de operaciones binarias.
El estado inicial y el final pueden compararse para obtener la diferencia exacta que se debe corregir.
Esa diferencia se expresa como un conjunto de ecuaciones donde cada luz impone una relación sobre los interruptores que afectan su estado.
Las ecuaciones se resuelven usando álgebra lineal en un sistema donde las operaciones son equivalentes a sumas modulares binarias.
Las soluciones representan conjuntos válidos de interruptores que producen el estado final.
Entre todas las soluciones posibles, se selecciona aquella con menor cantidad de interruptores activados.
Si no existe solución al sistema matemático, no es posible transformar la configuración inicial a la final.