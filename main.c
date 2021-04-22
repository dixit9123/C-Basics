//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA03                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "headers.h"

/*
 * Some #defines you might find useful.
 */
#define VALID   1
#define INVALID 0


#define CONVERSION_SUCCESS  1
#define CONVERSION_FAIL     0

int main(int argc, char **argv)
{
     // Check argument count
    if (argc != 3)
    {
        fprintf(stderr, "[ERROR] Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
     * In this part of main(), you could open the input file, read
     * the file names and process them in a loop.
     */

	//open file streams to read and write
	FILE *read=fopen(argv[1], "r");
	FILE *write=fopen(argv[2], "w");

	//check if error while openning streams
	if(read==NULL||write==NULL)
	{
		fprintf(stderr,"ERROR Fopen failed");
		exit(1);
	}

	char line[100];									//line reading in from file
	bool atEnd=getLine(read, line);					//reading in file
	int size=0;										//length of line
	while(!atEnd)									//atEnd checks if eof
	{
		int valid = check_validity(line, &size);	//checks if path is valid
		if(valid==1)
		{
			changePath(&size, line,  write);		//if valid change path
		}
		atEnd=getLine(read, line);					//read in next line
	}
	fclose(read);									//close file streams
	fclose(write);
    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
