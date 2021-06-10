SRC = pa2.c huffman.c
HDR = huffman.h

OBJ = $(patsubst %.c, %.o, $(SRC))

exe:$(OBJ)
	gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic $(SRC) -o pa2

%.o: %.c $(HDR)
	gcc -g -Wall -Werror -Wshadow -Wvla -pedantic -c $<

debug:
	gdb --args pa2 input.txt output.txt  

run:
	./pa2 input.txt output.txt