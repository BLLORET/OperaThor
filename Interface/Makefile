#Makefile
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall  -Wextra -std=c99 -O2 -g
LDFLAGS=
LDLIBS= -lm

OBJ= troisieme_interface.o identification.o fonction_interface.o operathor_interface.o
DEP= ${OBJ:.o=.d}

all: operathor_interface
 
operathor_interface: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} operathor_interface
 
-include ${DEP}
# END Makefile
