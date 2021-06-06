#include "shell_list.h"
#include "sequence.h"

/*
    Parameters:
        node - start position
        int - positions to move
    Task:
        returns a node n links down the list
*/
Node *advanceNode(Node *start, int n)
{
    if (n > 0)
    {
	    while ((start != NULL) && (n))
	    {
		    start = start->next;
	    	n--;
  	    }
    }
    return start;
}

//Finds size of linked list
int findSize(Node *start)
{
    int size=0;
    while(start!=NULL)
    {
        size++;
        start=start->next;
    }
    return size;
}

/*
Swaps 2 nodes while given head and the positions in the list
*/
Node* swap(Node *head, int a, int b)
{
    int size = findSize(head);
    Node *t1, *t2, *a1, *b1;
    a1 = advanceNode(head, a);
    b1 = advanceNode(head, b);
    if(a==b)
        return head;

    t1 = (Node *)NULL;
    t2 = (Node *)NULL;

    if(a<0 || a > b||a >=(size-1)||b>(size-1))
    {
        fprintf(stderr, "Invalid inputs for a & b\n");
        return head;
    }


    if((a > 0) && (a+1 == b))
    {
        t1 = advanceNode(head, a-1);
        t2 = advanceNode(head, b+1);
        
        t1->next = b1;
        b1->next = a1;
        a1->next = t2;  
    }
    else if(a == 0 && b==1)
    {
        t2 = advanceNode(head, 2);
        a1 -> next = t2;
        b1->next = a1;
        head = b1;
    }
    else if(a==0)
    {
        t1 = advanceNode(head, b-1);
        t2 = advanceNode(head, b+1);
        b1 -> next = a1->next;
        t1 -> next = a1;
        a1 -> next = t2;
        head = b1;
 
    }
    else if(a > 0)
    {
        t1 = advanceNode(head, a-1);
        t2 = advanceNode(head, b-1);
        a1 = t1->next;
        b1 = t2->next;
        Node *temp;

        temp =a1->next;
        a1->next=b1->next;
        t2->next=a1;
        t1->next=b1;
        b1->next= temp;
    }

    return head;
}
/*
Load a linked list from given file and return head
*/
Node *List_Load_From_File(char *filename)
{
    Node    *head  = malloc(sizeof(Node));      
    Node    *temp  = head;
    FILE    *fp    = fopen(filename, "r");
    int     size;
    int     read;

    if(fp==NULL)    
    {
        printf("Empty??");
        size=0;
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long s = ftell(fp);
    size = s / sizeof(long);

    if(size==0)
    {
        return NULL;
    }

    long *arr =malloc(sizeof(long)*size);
    fseek(fp, 0, SEEK_SET);
    read = fread(arr, sizeof(long), size, fp);
    for(int i =0; i<size; i++)
    {
        temp->value = arr[i];
        if(i!=size-1)
        {
            Node *next1=malloc(sizeof(Node));
            temp->next=next1;
            temp=temp->next;  
        }
    }
    free(arr);
    fclose(fp);
    if(read!=size)
    {
        printf("Size and read don't match");
    }
    return head;

}


int List_Save_To_File(char *filename, Node *list)
{
    int size=0;
    FILE *fp = fopen(filename, "w");
    if(fp==NULL)            
    {
        fprintf(stderr, "file wont open");
        return 0;
    }

    Node *point=list;
    
    while(point->next!=NULL)
    {
        fwrite(&(point->value), sizeof(long), 1, fp);
        point=point->next;
        size++;
    }
    fclose(fp);
    return size;
}

Node *List_Shellsort(Node *list, long *n_comp) 
{
    int *seq_size =malloc(sizeof(int));
    int size = findSize(list);
    long *seq = Generate_2p3q_Seq(size, seq_size);
    long temp, gap;
    int j; 

    for(int x=*seq_size-1; x >= 0; x--)
    {
        gap = seq[x];
        for(int i = gap; i < size; i++)
        {
            temp = advanceNode(list, i)->value;

            for(j = i; j>=gap && advanceNode(list, (j-gap))->value > temp; j-=gap)
            {
                list = swap(list, j-gap, j);
                (*n_comp)++;
            }
            advanceNode(list, j)->value = temp;
        }
    }
    return list;
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