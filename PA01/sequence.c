#include "sequence.h"

/*This file is a helper function for Shellsort
2p3q is a sequence of multiples of only 2 and 3. 
Values for 2p3q under 10 include 1,2,3,4,6,8,9.
Excluding 1 they all only contain prime factors of 2 and 3
*/
void sort(long*, int);


long *Generate_2p3q_Seq(int n, int *seq_size)
{
    int     power2=1;           //tracking powers of 2
    int     power2and3=1;       //tracking powers of 3
    long    *arr;               //array returning

    if(n==0)                    //if current array is 0
    { 
        *seq_size=0;            //return 0 for seq size and NULL for arr
        return NULL;
    } 
    while(n>power2)             //this loop is used to find size of arr
    {
        (*seq_size)++;          
        power2and3=power2;
        while(n > power2and3)   //multiply by 3 and increment seq_size until n is bigger
        {
            power2and3*=3;
            if(n > power2and3)
            {
                (*seq_size)++;
            }
        }
        power2*=2;              //increment power of 2
    }
    power2=1;       //reseting variables
    power2and3=1;
    arr=malloc(sizeof(long)*(*seq_size));   //use seq_size found above to allocate memory for array

    if(arr==NULL)       //if malloc fails
    {
        *seq_size=0;
        fprintf(stderr, "Allocation of sequence array failed\n");
        return NULL;
    }

    int index=0;
    while(n>power2)             //repeat of loop from before but to fill array
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
    sort(arr, *seq_size);       //sort in ascending order
    return arr;

}

void sort(long *arr, int n)     //selection sort
{
    int min;
    for(int i =0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]>arr[min])
            {
                min = j;
            }
        }
        long temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
