CC = gcc
CFLAGS = -I/usr/local/include/libxml2 -lxml2
LDFALGS = -lc

TARGET = app.out
OBJS = 	main.o xml-parser.o

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	clean

main : main.c
	$(CC) $(CFLAGS) main.c -o main

xml-parser : xml-parser.c
	$(CC) $(CFLAGS) -o xml-parser xml-parser.c

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) $@