/*
This file is used to run the code
*/

#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int main(int argc, char **argv)
{
    char *option = argv[1];
    char *inFile = argv[2];
    char *outFile = argv[3];

    long *arr;
    long *n_comp = malloc(sizeof(int));
    int  *size=malloc(sizeof(int));

    Node *head;

    if(option[1]=='a')
    {
        printf("1\n");
        arr = Array_Load_From_File(inFile, size);
        printf("%d\n", *size);
        Array_Shellsort(arr, *size, n_comp);
        Array_Save_To_File(outFile, arr, *size);
        printf("4\n");
    }
    else if(option[1]=='l')
    {
        head =List_Load_From_File(inFile);
        head =List_Shellsort(head, n_comp);
        List_Save_To_File(outFile, head);
    }
    printf("%ld\n", *n_comp);
        return 0;
}