# Early-Parser
Algoritmo de Earley implementado por JuanE García y Adrián Peña.

Implementado en C++ utilizando POO aplicando la técnica de programación dinámica.

Eficiencia: O(n^3).

Uso: ./earley "file_name" "string_to_check" ó creando las producciones a mano en el main, 

donde "file_name" es el archivo con las producciones de la gramática y
"string_to_check" es la palabra a comprobar si pertenece al lenguaje.

El formato de archivo de las producciones es: 
	cada una de las producciones en una linea de la forma: parte_izquierda">"parte_derecha"
	siempre siendo el símbolo 'S' el símbolo inicial.


!!!!
 Comprobar que las lineas del fichero con las producciones acaben solo con LF (según use Windows-Linux).
!!!!
