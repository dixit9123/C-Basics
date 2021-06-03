SRC=main.c sequence.c shell_array.c shell_list.c
HDR=sequence.h shell_array.h shell_list.h
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

fileComp:
	diff examples/15sa.b output15.b

clean: 
	rm exe *.o
