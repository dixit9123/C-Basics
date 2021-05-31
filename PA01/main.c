#include "sequence.h"
#include "shell_array.h"

int test2p3q();
int testLoadArr();
int testSaveArr();
int testArrShellSort();

int main()
{
    int stage=0;
    printf("What do you want to test out\n");
    printf("1: Test 2p3q Seqence\n");
    printf("2: Test Load Arr\n");
    printf("3: Test Save Arr\n");
    printf("4: Test Shell Sort Arr");
    //printf("3: for Linked List Sort\n");
    scanf("%d",&stage);

    if(stage==1)
    {
        test2p3q();  
        return 0;
    }
    if(stage==2)
    {
        testLoadArr();
        return 0;
    }
    
    if(stage==3)
    {
        testSaveArr();
        return 0;
    }
    if(stage==4)
    {
        testArrShellSort();
        return 0;
    }
    return 0;
}

int test2p3q()
{
    int* size=malloc(sizeof(int));
    int length=50;
    long* arr =Generate_2p3q_Seq(length, size);
    printf("For length %d\tSize Ends up as %d\n", length, *size);
    for(int i=0; i<*size;i++)
    {
        printf("arr[%d] = %ld\n", i, arr[i]);
    }
    free(size);
    free(arr);
    return 0;
}

int testLoadArr()
{
    int *size=malloc(sizeof(int));
    long * arr=Array_Load_From_File("examples/1M.b", size);
    printf("\n\n\nArray: %ld\n\n\n", arr[0]);

    /*for(int i = 0; i<*size; i++)
    {
         printf("%ld\n", arr[i]);
    }*/
    printf("Size of Array: %d\n", *size);
    free(arr);
    free(size);
    return 0;

}

int testSaveArr()
{
    int *size=malloc(sizeof(int));
    long *arr = Array_Load_From_File("examples/15.b", size);
    Array_Save_To_File("output.b", arr, *size);
    free(arr);
    free(size);
    return 0;
}

int testArrShellSort()
{
    int *size = malloc(sizeof(int));
    long *comps=malloc(sizeof(long));

    long *array=Array_Load_From_File("examples/15.b", size);
    Array_Shellsort(array, *size, comps);
    Array_Save_To_File("output.b", array, *size);
    return 0;
}