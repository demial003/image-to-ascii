CC=gcc
CFLAGS= -lm -Wall -std=c99 -g -fsanitize=address
SOURCES=$(wildcard *.c)
TARGET=main

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
