#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//checks validity of path
//
//
int check_validity(char line[], int *size)
{
	//checks if it starts with a '/'
	if(line[0]!='/')
	{
		return 0;
	}

	int i =0;
	while(line[i]!='\0'&&!isblank(line[i]))
	{
		i++;//finds end of path
	}
	
	*size = i;

	//checks if path ends w '/' or '.'
	if(line[i-2]=='/'||line[i-2]=='.')
	{
		return 0;
	}

	for(int j=0; j<(i-2); j++)
	{
		if(isalnum(line[j])!=0||line[j]=='/'||line[j]=='.'||line[j]=='-'||line[j]=='_')
		{
			//contains a legal character
		}
		else
		{
			//contains illegal character
			return 0;
		}
		if(line[j]=='/')
		{
			if(isdigit(line[j+1])||line[j+1]=='-')//file or directory starting w digit or '-'
			{
				return 0;
			}
		}
	}
	return 1;
}
