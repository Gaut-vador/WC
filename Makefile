# Ces cibles ne sont pas des vrais fichiers
.PHONY: clean
# On d�sactive toutes les r�gles implicites
.SUFFIXES:
# D�clarations de constantes
CC = gcc
CFLAGS = -Werror -W -Wall
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

# compilation finale
main: $(OBJECTS)
	$(CC) -o $@ $^

# R�gle g�n�rique : $< == le fichier .c compil�
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
