#include "shell_array.h"
#include "sequence.h"

long *Array_Load_From_File(char *filename, int *size)
{
    //  size/sizeof(long) = NUMBER OF INTEGERS
    // assign size after finding 
    // return address of array
    long *arr;
    //open file
    FILE *fp = fopen(filename, "r");
    if(fp==NULL)
    {
        printf("Empty??");
        *size=0;
        return NULL;
    }

    //find size
    fseek(fp, 0, SEEK_END);
    long s = ftell(fp);
    *size = s/sizeof(long);

    //check empty
    if(*size==0)
    {
        return NULL;
    }
    

    arr=malloc(sizeof(long)*(*size));
    fseek(fp, 0, SEEK_SET);
    fread(arr, sizeof(long),*size, fp);
    fclose(fp);  0
    return arr;

}


int Array_Save_To_File(char *filename, long *array, int size)
{
    return 0;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{

}