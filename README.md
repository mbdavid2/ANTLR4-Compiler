# CL-practica

Practica de Compiladores con ANTLR4

## TODO: 

-  ver si es int/char/float en:
  - write
  - assign
  - etc
  
  ditinguir floats en todos lados

 -Buscar en TODOS los ficheros los TODO's que hay que son bastantes

 - El typecheck 01 tiene un problema :/


- Mierdas de casts y conversiones en el codegen:
con float a:
a = 36.0 / 6.0; lo hace bien, da 6

pero a = 36.0 / 6; da infinito

si a es int, a = 3/2 da 1, bien. Si es float, da infinito tmb
