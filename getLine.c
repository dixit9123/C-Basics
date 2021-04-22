#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//function gets single line from textfile

void getLine(FILE* read, char line[])
{
	int count=0;			 //counter

	//empties out line[]
	for(int e=0;e<99; e++)
	{
		line[e]= ' ';
	}

	//reads by characters until new line is reached
	while(1)
	{
		line[count] = fgetc(read);
		if(ferror(read))
		{
			fprintf(stderr, "Rare Error Occured");
			exit(1);
		}

		if(feof(read))
		{
			return;
		}
		if(line[count]!= '\n')
		{
			count++;
		}
		else
			break;
	}
}
