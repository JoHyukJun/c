CC=gcc
CFLAGS=-c -Wall
SOURCE=jflib.c
OBJ=$(SOURCE:.c=.o)
EXE=jflib

all: $(SOURCE) $(EXE) clean

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)