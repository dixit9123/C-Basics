SRC=main.c getLine.c check_validity.c changePath.c
HDR=headers.h
OBJ=$(patsubst %.c, %.o, $(SRC))

exe: $(OBJ)
	gcc $(OBJ) -o exe

run:
	./exe file.txt output.txt

%.o: %.c $(HDR)
	gcc -g -Wall -Werror -c $<

clean:
	rm exe *.o output.txt
