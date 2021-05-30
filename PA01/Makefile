SRC=main.c sequence.c shell_array.c
HDR=sequence.h shell_array.h
OBJ=$(patsubst %.c, %.o, $(SRC))

exe: $(OBJ)
	gcc $(OBJ) -o exe

%.o: %.c $(HDR)
	gcc -g -Wall -Werror -c $<

run:
	./exe 

mem: 
	valgrind --leak-check=full ./exe

debug:
	gdb exe

clean: 
	rm exe *.o