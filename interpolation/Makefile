#Makefile
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall  -Wextra -std=c99 -O2 -g
LDFLAGS=
LDLIBS= -lm

OBJ= interpolation.o
DEP= ${OBJ:.o=.d}

all: interpolation
 
interpolation: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} interpolation
 
-include ${DEP}
# END Makefile
