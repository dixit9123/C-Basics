#include "shell_array.h"
#include "sequence.h"

void printArr(long*, int);

/*
    Parameters: 
        filename: name of file to read and save data from
        size: empty int pointer to save size of the array
    Task:
        load the data from given file into array
        return array and save the size
*/
long *Array_Load_From_File(char *filename, int *size)
{
    long *arr;
    int read;
    FILE *fp = fopen(filename, "r");            //checks if file opening fails
    if(fp==NULL)
    {
        fprintf(stderr,"File doesn't open");
        *size=0;
        return NULL;
    }

    fseek(fp, 0, SEEK_END);                     //find size
    long s = ftell(fp);
    *size = s/sizeof(long);
    
    arr=malloc(sizeof(long)*(*size));
    if(arr==NULL)                               //checks if malloc fails
    {
        fprintf(stderr,"Malloc Failed");
        *size=0;
        return NULL;
    }

    fseek(fp, 0, SEEK_SET);                     //fills array
    read = fread(arr, sizeof(long),*size, fp);
    fclose(fp);

    if(read != *size)
        printf("Size and read don't match");
    return NULL;

}

/*Parameters:
    filename: name of file to save array too
    array: data saving to file
    size: size of the array

    Saves array to a binary file with the given name
*/
int Array_Save_To_File(char *filename, long *array, int size)
{
    FILE *fp= fopen(filename, "w");
    if(fp==NULL)
    {
        fprintf(stderr, "File Couldn't open to Write");
        return 0;
    }

    fwrite(array, sizeof(long), size, fp);
    fclose(fp);
    return size;
}

/*Parameters: 
    array: sequence we need to sort
    size: size of array
    n_comp: int we are sending back as number of comparsions
    
Tasks:
    Call 2p3q for sequence and sort
    use seqence to shell sort array
*/
void Array_Shellsort(long *array, int size, long *n_comp)
{
    int * seq_size = malloc(sizeof(int));
    long *seq  = Generate_2p3q_Seq(size, seq_size);
    long temp, gap;

    for(int x=*seq_size-1; x>=0; x--)                           //step through sequence
    {
        gap = seq[x];
        for(int i=gap;i<size; i++)                              //moving across the list
        {
            temp=array[i];
            int j;
            for(j=i; j>=gap &&array[j-gap] > temp; j-=gap)      //comparing gaps in the array
            {
                array[j]=array[j-gap];
                (*n_comp)++;
            }
            array[j] = temp;
        }
    }
}

//helper for debugging
void printArr(long *arr, int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%ld\n", arr[i]);
    }
}