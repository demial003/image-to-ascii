CC=gcc
CFLAGS= -lm -std=c99  -g -fsanitize=address
SOURCES=$(wildcard *.c)
TARGET=main

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
