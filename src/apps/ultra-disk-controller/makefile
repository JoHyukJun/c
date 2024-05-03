CC = gcc
CFLAGS = -I/usr/local/include/libxml2 -lxml2
LDFALGS = -lc

TARGET = udc.out
OBJS = 	main.o xml-parser.o file-handler.o

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

main : main.c
	$(CC) $(CFLAGS) main.c -o main

xml-parser : xml-parser.c
	$(CC) $(CFLAGS) -o xml-parser xml-parser.c

file-handler : file-handler.c
	$(CC) $(CFLAGS) -o file-handler file-handler.c

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) $@