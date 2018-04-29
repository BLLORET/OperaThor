#Makefile
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall  -Wextra -std=c99 -O2 -g
LDFLAGS=
LDLIBS= -lm

OBJ= troisieme_terminal.o  identification.o fonction_terminal.o operathor_terminal.o
DEP= ${OBJ:.o=.d}

all: operathor_terminal
 
operathor_terminal: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} operathor_terminal
 
-include ${DEP}
# END Makefile
