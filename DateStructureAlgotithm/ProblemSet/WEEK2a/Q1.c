//WEEK2A 
// Q1

//(Memory management)
//Consider the following function:

/* Makes an array of 10 integers and returns a pointer to it */

/*
int *makeArrayOfInts(void) {
   int arr[10];
   int i;
   for (i=0; i<10; i++) {
      arr[i] = i;
   }
   return arr;
}
*/

//Explain what is wrong with this function. Rewrite the function so that it correctly achieves the intended result using  malloc().

# include <stdio.h>
# include <assert.h>
int * makeArrayofInts(void){
    int *arr;
    arr = malloc(10 * sizeof(int));
    assert(NULL != arr);
    int i;
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    return arr;
}


int main(int argc,char * argv[]){
    printf("Hello world!\n");
    int *array = makeArrayofInts();
    //for (int i = 0; i < 10;i++){
    //    //printf("#%d ", array[i]);
        //printf("%d\n", &array);
        printf("%d\n", array);
        printf("%d\n", *(array+1));
        printf("%d\n", *(array+2));
        printf("%d\n",sizeof(int));
        printf("%d\n", (&array[1]+sizeof(int)));
        printf("%d\n", *(&array[1]+sizeof(int)));
        //printf("%d\n", *(&array[1]+sizeof(int)));
        //printf("%d\n", &array[2]);
    //}
}