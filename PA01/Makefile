SRC=pa1.c sequence.c shell_array.c shell_list.c
HDR=sequence.h shell_array.h shell_list.h
OBJ=$(patsubst %.c, %.o, $(SRC))

exe: $(OBJ)
	gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic sequence.c shell_array.c shell_list.c pa1.c -o pa1

%.o: %.c $(HDR)
	gcc -g -Wall -Werror -c $<

run:
	./exe 

mem: 
	valgrind --leak-check=full ./pa1 -1 examples/1K.b output.b

debug:
	gdb exe

fileComp:
	diff examples/15.b outputList15.b

clean: 
	rm exe *.o *.b
