Sistemas operativos
Sección 1 
Grupo 8
Santiago
2021/2

Tarea 2

Integrantes:
Benjamin Parraguez

-----------------------------------------------------------------------

Archivos creados:

utils.h

utils.c

test.c

pstat.h

ps.c

Archivos modificados:

Usys.S

user.h

sysproc.c

syscall.h

syscall.c

spinlock.h

proc.h

proc.c

makefile

--------------------------------------------------------------------

utils.h: se crea y se define la definicion de random.

utils.c: archivo que permite generar numeros aleatorios dentro de un rango.

usys.S: se definen la llamada de sistema settickets y getpinfo

user.h: se definen settickets y getpinfo como llamadas a sistema

test.c: se crea el archivo que contiene la variable del total de tickets, que permite contar la cantidad de tickets totales en el proceso ademas de mostrar los resultados. 

sysproc.c: se implementa la logica para settickets y getpinfo.

syscall.h: se agregan las llamadas a sistema de settickets y getpinfo.

syscall.c: se definen las llamadas a sistema de settickets y getpinfo ademas de su arreglo.

spinlock.h: se le agrega un condicional que permite solucionar un problema con proc.h de doble declaracion 

pstat.h: se define la estructura de pstat, que permite definir los tickets y procesos

ps.c: se crea el archivo que permite determinar los procesos activos del SO con su respectiva informacion. 

proc.h: se agregan los tickets en la estructura del proc, ademas de definir una ptable que permitira trabajar con la llamada a sistema de getpinfo.

proc.c: Se modifica la funcion allocproc ajustando la cantidad de tickets para cada proceso, ticks y si estan en uso o no. Se modifica la funcion fork que incluya los punteros tickets,tickse in use para el uso del fork del nodo padre. Se crea la funcion number_tickets, que permite asignar la cantidad de tickets a cada uno de los procesos. Se modifica la funcion scheduler, que permite escoger al ticket ganador en cada loop de procesos.

Makefile: se agrego el archivo utils en el apartado de OBJS, además de ps en el apartado de UPROGS y EXTRA.

Información adicional: se puede ver mediante la llamada a sistema ps que proceso esta siendo utilizado y la cantidad de tickets y ticks (numero de veces que el proceso ha sido schedulerizado)

--------------------------------------------------------------------
Fuentes:
Microsoft PowerPoint - Clase_05.pptx 
https://iitd-plos.github.io/os/2020/ref/os-arpaci-dessau-book.pdf
https://www.youtube.com/watch?v=wN1hXsDpvxY
https://github.com/lehaoda/Operating-System-Class-Project---Add-Lottery-Scheduler-to-xv6
https://www.cs.virginia.edu/~cr4bd/4414/F2018/lottery.html
https://github.com/joeylemon/xv6-scheduler  [Gran parte del código e información fue sacada de este github]