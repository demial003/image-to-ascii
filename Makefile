CC=gcc
CFLAGS=-Wall -lm -std=c99 -Wextra -g -fsanitize=address,undefined -fwrapv
SOURCES=$(wildcard *.c)
TARGET=main

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
