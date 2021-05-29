#include "sequence.h"

int test2p3q();

int main()
{
    int stage=0;
    printf("What do you want to test out\n");
    printf("1: for Seqence\n");
    printf("2: for Array Sort\n");
    printf("3: for Linked List Sort\n");
    scanf("%d",&stage);

    if(stage==1)
    {
        test2p3q();  
        return 0;
    }
    return 0;
}

int test2p3q()
{
    int* size=malloc(sizeof(int));
    int length=16;
    long* arr =Generate_2p3q_Seq(length, size);
    printf("Size Ends up as %d\n", *size);
    for(int i=0; i<*size;i++)
    {
        printf("arr[%d] = %ld\n", i, arr[i]);
    }
    free(size);
    free(arr);
    return 0;
}

