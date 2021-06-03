#include "shell_array.h"
#include "sequence.h"

void swap(int*, int*);
void printArr(long*, int);

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
    fclose(fp);
    return arr;

}


int Array_Save_To_File(char *filename, long *array, int size)
{
    FILE *fp= fopen(filename, "w");
    if(fp==NULL)
    {
        fprintf(stderr, "File Couldn't open to Write");
        return 1;
    }

    fwrite(array, sizeof(long), size, fp);
    fclose(fp);
    return 0;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
    /*Parameters: 
        array: sequence we need to sort
        size: size of array
        n_comp: int we are sending back as number of comparsions
    
    Tasks:
        Call 2p3q for sequence and sort
    //Take insertion sort and from there adapt it to be shell sort
    */
    int * seq_size = malloc(sizeof(int));
    long *seq  = Generate_2p3q_Seq(size, seq_size);
    long temp, gap;

    for(int x=0; x<*seq_size; x++)
    {
        gap = seq[x];
        for(int i=gap;i<size; i++)
        {
            temp=array[i];
            int j;
            for(j=i; j>=gap &&array[j-gap] > temp; j-=gap)
            {
                array[j]=array[j-gap];
            }
            array[j] = temp;
        }
    }






/*    for(int i =0; i<*seq_size; i++)
    {
        printf("I: %d\n",i);
        k =seq[i];
        //printf("gap=%ld", gap);
        printf("K: %d\n",k);
        for (int j = k; i < size-1; i++) {
            temp = array[j];
            i=j;
            printf("J: %d", j);
             Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position 
            while (i >= k && array[i-k] > temp) {
                (*n_comp)++;
                array[i] = array[i-k];
                i = i - k;
            }
            array[i] = temp;
        }
    }*/
    printArr(array, size);
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printArr(long *arr, int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%ld\n", arr[i]);
    }
}