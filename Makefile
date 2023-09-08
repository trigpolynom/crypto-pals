CC = gcc
CFLAGS = -g

LIB_SOURCES = $(wildcard lib/*.c)
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

set1_challenge1_1: $(LIB_OBJECTS) set1/challenge1_1/main.c
	$(CC) $(CFLAGS) -o set1/challenge1_1/main $^

set1_challenge1_2: $(LIB_OBJECTS) set1/challenge1_2/main.c
	$(CC) $(CFLAGS) -o set1/challenge1_2/main $^

set1_challenge1_3: $(LIB_OBJECTS) set1/challenge1_3/main.c
	$(CC) $(CFLAGS) -o set1/challenge1_3/main $^

set1_challenge1_4: $(LIB_OBJECTS) set1/challenge1_4/main.c
	$(CC) $(CFLAGS) -o set1/challenge1_4/main $^

clean:
	rm -f $(LIB_OBJECTS) set1/challenge1_1/main set1/challenge1_2/main set1/challenge1_3/main set1/challenge1_4/main

.PHONY: clean
