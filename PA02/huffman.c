#include "huffman.h"


/*
    Huffman Encoding:

    1) find frequency list of characters
    2) build tree
    3) get encoding for each letter
    4) get topography
    5) put topography on new file
    6) compress on new file

*/

//The function that puts everything together
long *compress(char *inFile, char *outFile)
{
    int fileSize =0;
    int *freq = frequencyList(inFile, &fileSize);
    ListNode *head = buildList(freq);
    //ListNode *temp = head;
    int listSize = findSize(head);
    int treeSize =0;
    //printf("List Size: %d", listSize);


    Node *root = merge(head, listSize);
    printTree(root, &treeSize);
    //ListNode *head = buildList(freq);
    /*ListNode *temp = head;
    while(temp!=NULL)
    {
        printf("%c: %d ", temp->value->val, temp->value->freq);
        temp=temp->next;
    }*/
    return NULL;
}

//Prints the linked list
void printList(ListNode *temp)
{
    int counter=0;
    while(temp!=NULL)
    {
        printf("ListNode %d\n", counter);
        printf("Node val %c\n freq %d\n\n\n", temp->value->val, temp->value->freq);
        temp = temp->next;
        counter++;
    }
}

//Finds size of linked list
int findSize(ListNode *start)
{
    int size = 0;
    while(start!=NULL)
    {
        size++;
        start = start -> next;
    }
    return size-1;
}

//What I was trying to use to insert the nodes in increasing order of frequency 
//this is where the segementation fault is.
void insert(ListNode **head, ListNode *toAdd)
{
    ListNode *current;
    if(*head==NULL||(*head)->value->freq >= toAdd->value->freq)
    {
        toAdd->next = *head;
        *head = toAdd;
        return;
    }
    
    current = *head;

    while(current->next!=NULL && current->next->value->freq < toAdd->value->freq)
    {
        current = current->next;
    }
    toAdd->next = current->next;
    current->next = toAdd;
        //printList(*head);
}


//This function takes the frequency table and builds a linked list of nodes
ListNode *buildList(int *freq)
{
    ListNode *head =NULL;

    for(int i=0; i<255; i++)
    {
        if(freq[i]!=0)
        {
            //printf("i: %d", i);
            Node     *letter = malloc(sizeof(Node));
            ListNode *nextNode = malloc(sizeof(ListNode));
            if(letter==NULL||nextNode==NULL)
            {
                fprintf(stderr, "Malloc failed");
                return NULL;
            }

            letter->val = i;
            letter->freq = freq[i];
            letter->left =NULL;
            letter->right=NULL;

            nextNode->value = letter;
            nextNode->next=NULL;

            insert(&head, nextNode);
        }
    }
    //printList(head);
    return head;
}

int *frequencyList(char *inFile, int *inFileSize)
{
    FILE *fp = fopen(inFile, "r");
    int input;
    int *freq = malloc(sizeof(int)*256);
    if(freq==NULL)
    {
        fprintf(stderr, "Malloc failed");
        return 0;
    }
    if(fp==NULL)        
    {
        fprintf(stderr, "File didn't open");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    *inFileSize = ftell(fp)*sizeof(char);
    fseek(fp, 0, SEEK_SET);
    //printf("Size: %d \n", *inFileSize);
    while(!feof(fp))
    {

        input = fgetc(fp);
        //printf("Char: %c %d\n", input, input);
        freq[input] = freq[input] + 1;
    }
    fclose(fp);
    return freq;
}

Node *merge(ListNode *head, int size)
{
    ListNode *cur;
    ListNode *next1;
    //int *tree=malloc(sizeof(int));
    //*tree = 0;

    if(head==NULL)
    {
        fprintf(stderr, "List is Empty");
    }
    cur = head;
    next1 = head->next;

    for(int i=0; i<size; i++)
    {
        Node *comb=malloc(sizeof(Node));

        comb->left = cur->value;
        comb->right = next1->value;
        comb->freq = comb->left->freq + comb->right->freq;
        next1->value = comb;
        free(cur);
        cur = next1->next;
        insert(&cur, next1);
        next1 = cur->next;
    }
    //printTree(cur->value, tree);
    //free(tree);
    return cur->value;
}

void printTree(Node *root, int *size)
{
    if(root!=NULL)
    {
        (*size)++;
        printTree(root->left, size);
        printf("#%d, char: %d freq: %d\n\n", *size, root->val, root->freq);
        printTree(root->right, size);
        
    }
}
