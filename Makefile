#Makefile
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall -Wextra -std=c99 -O2 -g
LDFLAGS=
LDLIBS=

OBJ= identification.o fonction.o operathor.o
DEP= ${OBJ:.o=.d}

all: operathor
 
operathor: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} operathor
 
-include ${DEP}
# END Makefile
