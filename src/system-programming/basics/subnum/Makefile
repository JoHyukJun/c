# Makefile


CC=gcc
CFLAGS=
OBJS=main.o subnum.o
LIBS=
all : sub.out

sub.out : $(OBJS)
	$(CC) $(CFLAGS) -o sub.out $(OBJS) $(LIBS)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c
subnum.o : subnum.c
	$(CC) $(CFLAGS) -c subnum.c

clean:
	rm -f $(OBJS) sub.out *.o core