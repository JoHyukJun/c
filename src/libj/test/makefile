.PHONY: all clean

LIB_PATH = ../libobj
LIB_NAME = j
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS = -Wall -Werror -pthread

all: $(PROGS)

%: %.c
	$(CC) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)