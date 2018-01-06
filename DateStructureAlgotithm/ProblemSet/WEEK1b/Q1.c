/*

(Stack ADO) 
Modify the Stack ADO from the lecture 
(Stack.h and Stack.c) to implement a stack of integers.



*/




// Stack ADO implementation ... COMP9024 17s2

//#include "Stack.h"
#include <assert.h>
#include <stdio.h>

#define MAXITEMS 10

static struct {
   int item[MAXITEMS];
   int  top;
} stackObject;  // defines the Data Object

// Stack ADO header file ... COMP9024 17s2

void StackInit();      // set up empty stack
int  StackIsEmpty();   // check whether stack is empty
void StackPush(int);  // insert char on top of stack
int StackPop();       // remove char from top of stack

void StackInit() {         // set up empty stack
   stackObject.top = -1;
}

int StackIsEmpty() {       // check whether stack is empty
   return (stackObject.top < 0);
}

void StackPush(int n) {  // insert char on top of stack
   assert(stackObject.top < MAXITEMS-1);
   stackObject.top++;
   int i = stackObject.top;
   stackObject.item[i] = n;
}

int StackPop() {         // remove char from top of stack
   assert(stackObject.top > -1);
   int i = stackObject.top;
   int n = stackObject.item[i];
   stackObject.top--;
   return n;
}

int main(void){
    int i, n, number;
    StackInit();
    printf("Enter a positive number:");
    if(scanf("%d",&n)==1 && (n>0)){

        for (i = 0; i < n;i++){
            printf("Enter a number:");
            scanf("%d", &number);
            StackPush(number);
        }
        while (!StackIsEmpty()){
            printf("%d\n", StackPop());
        }
    }
    return 0;
}