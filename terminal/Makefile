#Makefile
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall  -Wextra -std=c99 -O2 -g
LDFLAGS=
LDLIBS= -lm

OBJ= troisieme.o identification.o fonction_terminal.o operathor.o
DEP= ${OBJ:.o=.d}

all: operathor
 
operathor: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} operathor
 
-include ${DEP}
# END Makefile
