#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void changePath(int* size, char* line, FILE*write)
{
	char *period = strchr(line, '.');	//extension
	char *toAdd=" ";					//what we insert to the string
	int index=0;						//index where we insert
	char newPath [100];					//new Path

	if(period==NULL)					//if no extension
	{
		toAdd="misc/";
	}
	else								//checks to see if it equals .c or .py
	{
		int result = strncmp(period, ".c", 2);
		int result2= strncmp(period, ".py ", 3);

		if(result==0)
		{
			toAdd="c/";
		}
		else if(result2==0)
		{
			toAdd="py/";
		}
		else
		{
			toAdd="misc/";
		}
	}
	
	//finds last / to insert the 'toAdd' string 
	for(int i=0; i<*size; i++)
	{
		if(line[i]=='/')
		{
			index=i;
		}
	}
	index++;

	//inserts string
	strncpy(newPath, line, index);
	newPath[index]='\0';
	strcat(newPath, toAdd);
	strcat(newPath, line+index);
	
	//prints to output file without the spaces
	for(int j=0; j<100; j++)
	{
		if(newPath[j]!=' ')
		{
			fprintf(write,"%c",newPath[j]);
		}
	}
}
