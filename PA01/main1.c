/*
This is meant to be used as a tester function for the projects
    We give you the option of choosing which function to test 
    and debugging/testing different values happens here
*/

#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

/*
Each function is testing a different function from the 3 files
sequence.c
shell_array.c
shell_list.c
*/

int test2p3q();             //Generate_2p3q_Seq: generating 2p3q sequence as shellsort helper

int testLoadArr();          //Array_Load_From_File: loads array from binary file
int testSaveArr();          //Array_Save_To_File: saves sorted array to file
int testArrShellSort();     //Array_Shellsort: sorts file w/ shell sort

int testLoadList();         //List_Load_From_File: loads list from file
int testListToFile();       //List_Save_To_File: saves list to file
int testListSort();         //List_Shellsort: sorts list(hard part)
int testSwap();

int testArray();            //test complete array section
int testList();             //test complete list section


int testing()
{
    int stage=0;
    printf("What do you want to test out\n");       //User chooses what to test
    printf("1: Test 2p3q Seqence\n");

    printf("2: Test Load Arr\n");                   //Test Array part of project 
    printf("3: Test Save Arr\n");
    printf("4: Test Shell Sort Arr\n");
    printf("5: Test Whole Array Part\n");

    printf("6: Test Load Linked List\n");           //Test Linked List part of project
    printf("7: Test List to File\n");
    printf("8: Test List Sort\n");
    printf("9: Test Whole List Part\n");
    printf("10: Test Swap\n");

    printf("0: Test Lists Sort\n");

    scanf("%d",&stage);     //scan

    switch(stage)           //call tester function
    {
        case 0:
            testListSort();
            break;
        case 1:
            test2p3q();
            break;
        case 2:
            testLoadArr();
            break;
        case 3:
            testSaveArr();
            break;
        case 4:
            testArrShellSort();
            break;
        case 5:
            testArray();
            break;
        case 6:
            testLoadList();
            break;
        case 7:
            test2p3q();
            break;
        case 8:
            testLoadArr();
            break;
        case 9:
            testList();
        case 10:
            testSwap();
            break;
    }
    return 0;
}

void printList(Node *list)
{
    while(list!=NULL)
    {
        printf("%ld\n",list->value);
        list=list->next;
    }
}

int testListSort()
{
    char *fileInput = "examples/15.b";
    long *n_comp=malloc(sizeof(long));

    Node *list = List_Load_From_File(fileInput);
    printf("Unsorted:\n");
    printList(list);
    list=List_Shellsort(list, n_comp);
    printf("Sorted:\n");
    printList(list);
    return 0;
}


//Testing 2p3q in sequence.c
int testSwap()
{
    Node *head, *temp;
    head = malloc(sizeof(Node));
    temp = head;

    for(double i =0; i<15; i++)
    {
        temp->value = i;
        if(i<14)
        {
            Node *next1 = malloc(sizeof(Node));
            temp->next =next1;
            temp=temp->next;
        }
    }

    temp = head;

    printf("Unswapped: ");
    while(temp!=NULL)
    {
        printf("%ld ", temp->value);
        temp=temp->next;
    }

    printf("\n");
    head = swap(head, 0, 6);
    temp = head;
    printf("Swapped:   ");
    while(temp!=NULL)
    {
        printf("%ld ", temp->value);
        temp=temp->next;
    }

    return 0;
}

int test2p3q()
{
    int* size=malloc(sizeof(int));
    int length=16;
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
    int     *size = malloc(sizeof(int));
    long    *arr = Array_Load_From_File("examples/15.b", size);

    if(*size<100)
    {
        for(int i = 0; i<*size; i++)
        {
            printf("%ld\n", arr[i]);
        }
    }

    printf("Size of Array: %d\n", *size);
    free(arr);
    free(size);
    return 0;

}

//Testing writing to file from Array
//use make fileComp to compare the 2 files
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
//use make fileComp to compare the 2 files
int testArrShellSort()
{
    int *size = malloc(sizeof(int));
    long *comps=malloc(sizeof(long));

    long *array=Array_Load_From_File("examples/1K.b", size);
    //printArr1(array, *size);
    Array_Shellsort(array, *size, comps);

    Array_Save_To_File("output.b", array, *size);
    free(size);
    free(comps);
    return 0;
}

//Testing the entire array process together
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

    free(size);
    free(size2);
    free(comps);
    free(array);
    free(arrayAns);

    return 0;
}


//Testing loading list from file
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
    //destroyTree(head);
    return 0;
}



//Testing saving the list to file
int testListToFile()
{
    Node *head = List_Load_From_File("examples/15.b");
    printf("%ld\n\n\n", head->value);
    List_Save_To_File("outputList15.b", head);
    //destroyTree(head);
    return 0;
}

//Testing the whole list together
int testList()
{
    return 0;
}