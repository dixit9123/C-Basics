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
    //takes in array of long and sorts them
    //size: size of array
    //n_comp: number of comparisons
    //call 2p3q to get sequence and sequence size
    int *seq_size=malloc(sizeof(int));
    long *seq = Generate_2p3q_Seq(size, seq_size);
    int k;
    long temp;
    printf("Arr before sort: \n");
    printArr(array, size);
    for(int i=0; i<*seq_size; i++)
    {
        k=seq[i];
        for(int j=k; j<size; j++)
        {
            temp=array[j];
            i=j;
            while(i>=k&&array[i-k]>temp)
            {
                (*n_comp)+=2;
                array[i]=array[i-k];
                i=i-k;
            }
            (*n_comp)++;
            array[i]=temp;
        }
    }
    printf("Comp= %ld\n", *n_comp);
    printf("Arr after sort:\n");
    printArr(array, size);
    //printf("Comp= %ld", *n_comp);

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