#ifndef __huffman__
#define __huffman__

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    struct ListNode *next;
    struct _Node *value;

}ListNode;

typedef struct _Node
{
    struct _Node     *left;
    struct _Node     *right;
    char            val;
    int             freq;
    
}Node;

long *compress(char *inFile, char *outFile);
int *frequencyList(char *inFile, int *inFileSize);
ListNode *buildList(int *freq);
int findSize(ListNode *start);
Node *merge(ListNode *head, int size);
void insert(ListNode **head, ListNode *toAdd);
void printTree(Node *root, int *size);
#endif