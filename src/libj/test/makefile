.PHONY: all clean

LIB_PATH = ../libobj
LIB_FLAGS = -lj.file \
		   	-lj.sam \
			-lj.sem \
			-lj.time \
			-lj.json \
			-lj.db \
			-lj.log \
			-lj.hash
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS = -Wall -Werror -pthread -I$(INCLUDE_FLAGS)
INCLUDE_DIR = ../include

# Find all subdirectories in INCLUDE_DIR
INCLUDE_DIRS = $(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))

all: $(PROGS)

%: %.c
	$(CC) -L$(LIB_PATH) $(LIB_FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)