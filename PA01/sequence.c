#include "sequence.h"

long *Generate_2p3q_Seq(int n, int *seq_size)
{
    int power2,power2and3;
    long *arr;
    
    while(power2 < n)
    {
        power2and3=power2;
        while(power2and3 < n)
        {
            *seq_size++;
            power2and3*=3;
        }
        power2*=2;
    }
    printf("Length = %d", *seq_size);
    *arr = malloc(sizeof(long)*(*seq_size));
    
    if(*arr==NULL)
    {
        *seq_size=0;
        return NULL;
    }
    return NULL;
}

int main(void)
{
    int n=16;
    int *seq_s=0;
    Generate_2p3q_Seq(n, seq_s);
    printf("%d", seq_s);
}
