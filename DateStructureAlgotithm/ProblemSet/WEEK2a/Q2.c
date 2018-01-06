
/*

(Memory management) 
Consider the following program: 
#include <stdio.h>
#include <stdlib.h>

void func(int *a) {
   a = malloc(sizeof(int));
}

int main(void) {
   int *p;
   func(p);
   *p = 6;
   printf("%d\n",*p);
   free(p);
   return 0;
}
Explain what is wrong with this program. 

*/



# include <stdio.h>
# include <assert.h>

void mal(int **v){
    *v = malloc(sizeof(int));
}

int main(int argc, char *argv[]){
    int *p;
    mal(&p);
    *p = 1;
    printf("%d\n", *p);
    return 0;
}