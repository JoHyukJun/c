# Makefile


CC=gcc
CFLAGS=
OBJS=main.o addnum.o
LIBS=
all : add.out

add.out : $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c
addnum.o : addnum.c
	$(CC) $(CFLAGS) -c addnum.c

clean:
	rm -f $(OBJS) add.out *.o core