Sistemas operativos
Sección 1 
Grupo 8
Santiago
2021/2

Integrantes:
Benjamin Parraguez

-----------------------------------------------------------------------

Archivos creados:

cuenta.c

Archivos modificados:

MAKEFILE
Syscall.h
Syscall.c
Sysproc.c
proc.c
defs.h
user.h
usys.s

(Se reutilizo el codigo de la tarea 1 para realizar la llamada a sistema, es por eso que la funcion getprocs permite trabajar la actividad acerca de la memoria)

--------------------------------------------------------------------

Cuenta.c:
Se crea el cuenta.c que permite llamar a sistema

MAKEFILE:
Se agrego _cuenta a la parte de UPROGS y cuenta.c a la parte de Extra

Syscall.h:
Se definiio la llamada a sistema sys_getprocs con el numero 22

Syscall.c:
Se creo el apartado de extern de sys_getprocs ademas de incluirla con su respectiva matriz

Sysproc.c:
Se crea la funcion de sys_procs que hace retorna la funcion de getprocs

proc.c:
Se crea la funcion getprocs, donde esta toda la logica para trabajar la direccion virtual y fisica.

defs.h:
Se menciona el tipo de funcion de getprocs en el apartado de proc.c 

user.h:
Se declara que la funcion getprocs es una llamada a sistema

usys.s:
se define que getprocs es una llamada a sistema

vm.c:
Se modifico el apartado de walkpgdir para que deje de ser estatico y pueda ser manipulable.


--------------------------------------------------------------------
Fuentes:
Microsoft PowerPoint - Clase_02.pptx 
https://www.youtube.com/watch?v=21SVYiKhcwM
https://stackoverflow.com/questions/57745250/how-to-add-a-system-call-to-find-the-number-of-processes-in-xv6
https://stackoverflow.com/questions/8021774/how-do-i-add-a-system-call-utility-in-xv6
https://www.youtube.com/watch?v=qZ16UodDlz8&t=734s
https://iitd-plos.github.io/os/2020/ref/os-arpaci-dessau-book.pdf
https://www.youtube.com/watch?v=Ib6U4eQbTxU&t=2s
https://www.ics.uci.edu/~aburtsev/238P/2018winter/hw/hw3-dump-pid-syscall.html
https://stackoverflow.com/questions/46807664/how-to-get-pgdir-in-xv6