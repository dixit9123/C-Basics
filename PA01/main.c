#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int test2p3q();
int testLoadArr();
int testSaveArr();
int testArrShellSort();
int testLoadList();
int testListToFile();
int testArray();

/*
This is meant to be used as a tester function for the projects
    We give you the option of choosing which function to test 
    and debugging/testing different values happens here
*/
int main()
{
    int stage=0;
    printf("What do you want to test out\n");
    printf("1: Test 2p3q Seqence\n");
    printf("2: Test Load Arr\n");
    printf("3: Test Save Arr\n");
    printf("4: Test Shell Sort Arr\n");
    printf("5: Test Load Linked List\n");
    printf("6: Test Whole Array Part\n");
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
    if(stage==5)
    {
        testLoadList();
        return 0;
    }
    if(stage==6)
    {
        testArray();
    }
    return 0;
}

//Testing 2p3q in sequence.c

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

//Testing Array from File
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

//Testing writing to file from Array
int testSaveArr()
{
    int *size=malloc(sizeof(int));
    long *arr = Array_Load_From_File("examples/15.b", size);
    Array_Save_To_File("output.b", arr, *size);
    free(arr);
    free(size);
    return 0;
}

//Testing shell sort for array

int testArrShellSort()
{
    int *size = malloc(sizeof(int));
    long *comps=malloc(sizeof(long));

    long *array=Array_Load_From_File("examples/1K.b", size);
    Array_Shellsort(array, *size, comps);
    Array_Save_To_File("output.b", array, *size);
    return 0;
}

int testLoadList()
{
    Node *head=List_Load_From_File("examples/15.b");
    Node* list=head;
    printf("values\n");
    while(list!=NULL)
    {
        printf("%ld\n", list->value);
        list=list->next;
    }
    destroyTree(head);
    return 0;
}

int testListToFile()
{
    return 0;
}


int testArray()
{
    int     *size = malloc(sizeof(int));
    int     *size2 = malloc(sizeof(int));
    long    *comps=malloc(sizeof(long));
    char    *filenameAnswer = "examples/15sa.b";
    char    *filenameOutput = "output15.b";
    char    *filenameInput = "examples/15.b";

    long *array=Array_Load_From_File(filenameInput, size);
    Array_Shellsort(array, *size, comps);
    printf("Number of computations is: %ld\n", *comps);
    long *arrayAns=Array_Load_From_File(filenameAnswer, size2);

    for(int i=0; i<*size;i++)
    {
        if(arrayAns[i]!=array[i])
        {
            printf("Index: %d is different\n", i);
            printf("Array[%d]=%ld and ArrayAns[%d]=%ld\n", i, array[i], i, arrayAns[i]);
        }
    }
    printf("Saved to file %s\n", filenameOutput);
    Array_Save_To_File(filenameOutput, array, *size);
    return 0;
}