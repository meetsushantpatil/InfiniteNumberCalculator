//
//  main.c
//  InfiniteCalculator
//
//  Created by Sushant Patil on 20/11/15.
//  Copyright © 2015 Sushant Patil. All rights reserved.
//

#include <stdio.h>

//Read a file from the end
void printFile(FILE *fp)
{
    char c;
    while((c = getc(fp)) != EOF)
        printf("%c", c);
}


//Add nodes

//print the list

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    fp = fopen("number_1.txt","r");
    printFile(fp);
    printf("\n");
    fp = fopen("number_2.txt","r");
    printFile(fp);
    
    
    // insert code here...
    printf("\nHello, World!\n");
    printf("Awesome");
    return 0;
}
