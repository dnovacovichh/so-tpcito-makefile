# Globales
CC = gcc

SRC = $(shell find ./src -type f -iname "*.c" -exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o) #De la variable SRC agarra todo lo que sea *.c  y ponelo en la carpeta obj/*.o

build: makefolder $(OBJ)

LINK = -lpthread -lcommons -lm
CFLAGS = -c

debug: CFLAGS := $(CFLAGS) -g
debug: build

./obj/%.o: ./src/%.c # REGLA
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

makefolder:  # Crea carpeta obj
	if [ ! -d ./obj ]; then mkdir obj; fi
