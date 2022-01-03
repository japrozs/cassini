CC = gcc
CFLAGS = -Wall -I include -g -std=c11
SRC = $(wildcard *.c src/*.c src/**/*.c)
HEAD = $(wildcard include/*.h include/**/*.h)
OBJ = $(SRC:.c=.o)
EXEC = bin/csn
WIN_EXEC=bin/csn.exe

all: clean $(OBJ) $(EXEC) $(HEAD)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@
	$(CC) $^ -o $(WIN_EXEC)
	rm -rf src/*.o
	rm -rf src/**/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

build:
	make
	cd bin
	zip csn.zip ./csn
	zip windows.zip ./$(WIN_EXEC)
	cd ..
	make clean

install:
	chmod +x install.sh
	./install.sh

clean:
	rm -rf *.o src/*.o src/**/*.o $(EXEC) $(WIN_EXEC)