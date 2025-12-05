CC=gcc
CFLAGS=-g -Wall
EXECUTABLES=hello subtract domath

.PHONY: all clean

all: $(EXECUTABLES)
SRC_EXT=.c

$(EXECUTABLES):
	$(CC) $(CFLAGS) $@$(SRC_EXT) -o $@

clean:
	rm -f $(EXECUTABLES)
