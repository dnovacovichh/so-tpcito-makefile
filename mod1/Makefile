# Globales
CC = gcc
OUTFILE = mod1.out


# SRC -> find ./src -type f -iname "*.c" -exec basename {} \; (Da una lista de *.c)
SRC = $(shell find ./src -type f -iname "*.c" -exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o) #De la variable SRC agarra todo lo que sea *.c  y lo pone en la carpeta obj/*.o
SHARED = $(shell find ../shared/obj/*.o)

build: makefolder makeshared $(OBJ)
	$(CC) -o $(OUTFILE) main.c $(OBJ) $(SHARED)

LINK = -lpthread -lcommons -lm
CFLAGS = -c

debug: CFLAGS := $(CFLAGS) -g
debug: makeshared_debug build

./obj/%.o: ./src/%.c # REGLA
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

makefolder:  # Crea carpeta obj
	if [ ! -d ./obj ]; then mkdir obj; fi

makeshared:
	make -C ../shared

makeshared_debug:
	 make debug -C ../shared

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind.log ./$(OUTFILE)


# Clean

clean:
	rm -rf obj
	rm -rf *.out
	rm -rf *.log
	make clean -C ../shared