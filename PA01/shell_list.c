#include "shell_list.h"
#include "sequence.h"
#include "shell_array.h"
//This program will load binary files into linked lists and use shell sort to sort the it and load it into an output file



//This function will read in from a binary file and load it into a linked list return the list

void printArr1(long *arr, int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%ld\n", arr[i]);
    }
}

Node *List_Load_From_File(char *filename)
{
    //open file
    Node *head = malloc(sizeof(Node));
    Node *temp = head;
    FILE *fp = fopen(filename, "r");
    int size;
    if(fp==NULL)
    {
        printf("Empty??");
        size=0;
        return NULL;
    }

    //find size
    fseek(fp, 0, SEEK_END);
    long s = ftell(fp);
    size = s/sizeof(long);
    printf("Size: %d\n", size);
    //check empty
    if(size==0)
    {
        return NULL;
    }

    long *arr =malloc(sizeof(long)*size);
    fseek(fp, 0, SEEK_SET);
    fread(arr, sizeof(long), size, fp);
    printArr1(arr, size);
    for(int i =0; i<size; i++)
    {
        temp->value = arr[i];
        Node *next1=malloc(sizeof(Node));
        temp->next=next1;
        temp=temp->next;    
    }
    free(arr);
    fclose(fp);
    return head;

}


int List_Save_To_File(char *filename, Node *list)
{
    FILE *fp = fopen("outputList.b", "w");
    Node *point=list;
    while(list!=NULL)
    {
        fwrite(&(point->value), sizeof(long), 1, fp);
        point=point->next;
    }
    
    return 0;
}

Node *List_Shellsort(Node *list, long *n_comp) 
{
    return NULL;
}

void destroyTree(Node *list)
{
    Node *current=list;
    Node *next;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
}