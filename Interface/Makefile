## Makefile dectection of characters
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags gtk+-3.0` -MMD -D_XOPEN_SOURCE=500
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs gtk+-3.0` -lm -export-dynamic -rdynamic
 
OBJ=main.o matrice.o complex.o troisieme_interface.o identification.o fonction_interface.o PrintMain.o syst.o interpolation.o interpolation_lineaire.o interpolation_newton.o 
DEP= ${OBJ:.o=.d}
 
all: main
 
main: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} main
 
-include ${DEP}
 
# END
