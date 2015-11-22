//
//  main.c
//  InfiniteCalculator
//
//  Created by Sushant Patil on 20/11/15.
//  Copyright © 2015 Sushant Patil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Basic Block Structure
typedef struct Block
{
    int data;
    int block_number;
    struct Block *nxt_block;
}Block;

//Read blocks from the file
void setFilePointer(FILE *fp, int block_number, int block_size)
{
    fseek(fp, -block_number*block_size , SEEK_END);
}

//Read a file from the end
void printFile(FILE *fp)
{
    char c;
    while((c = getc(fp)) != EOF)
        printf("%c", c);
}

int readBlock(FILE *fp,int block_size)
{
    char c;
    int i=0, tmp[block_size];
    int data = 0;
    setFilePointer(fp,1,block_size);
    while((c = getc(fp)) != EOF)
    {
        printf("%c", c);
        tmp[i] = (int)c-48;
        i++;
        if(i==block_size)
            break;
    }
    
    for (i=0; i<block_size; i++)
    {
        data += tmp[i]*(pow(10,block_size-i-1));
    }
    
    return data;
}

//Add nodes
void addNode(FILE *fp,Block *OperatorOne, int block_number)
{
    
    Block *x;
    x= (Block *)malloc(sizeof(Block));
    x = OperatorOne;
    x->data = readBlock(fp,2);
    printf("\n%d", readBlock(fp,2));
    x->nxt_block = NULL;
    x->block_number = block_number;
    
}

//print the list
void printList(Block *listPtr)
{
    while (listPtr != NULL)
    {
        printf("The block number %d is :%d\n",listPtr->block_number,listPtr->data);
        listPtr = listPtr->nxt_block;
    }
}
//Initailise a list

//print the list

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    fp = fopen("number_1.txt","r");
    //printf("\n%d", readBlock(fp,2));
    fp = fopen("number_2.txt","r");
    //printFile(fp);
    
    // insert code here...
    Block *OperatorOne;
    addNode(fp, OperatorOne, 1);
    printList(OperatorOne);
    printf("\nHello, World!\n");
    printf("Awesome");
    return 0;
}
