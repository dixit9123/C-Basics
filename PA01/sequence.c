#include "sequence.h"

void sort(long*, int);

long *Generate_2p3q_Seq(int n, int *seq_size)
{
    int power2=1;
    int power2and3=1;
    if(n==0)
    {
        *seq_size=0;
        return 0;
    } 
    while(n>power2)
    {
        (*seq_size)++;
        power2and3=power2;
        while(n>power2and3)
        {
            power2and3*=3;
            if(n>power2and3)
            {
                (*seq_size)++;
            }
        }
        power2*=2;
    }
    power2=1;
    power2and3=1;
    long* arr=malloc(sizeof(long)*(*seq_size));
    if(arr==NULL)
    {
        *seq_size=0;
        return NULL;
    }
    int index=0;
    while(n>power2)
    {
        arr[index]=power2;
        index++;
        power2and3=power2;
        while(n>power2and3)
        {
            power2and3*=3;
            if(n>power2and3)
            {
                arr[index]=power2and3;
                index++;
            }
        }
        power2*=2;
    }
    sort(arr, *seq_size);
    return arr;

}

void sort(long *arr, int n)
{
    int min;
    for(int i =0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        long temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
