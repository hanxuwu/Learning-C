#include <stdio.h>
void swap(int, int);
void swap1(int*, int*);

int main(void){
    printf("Please enjoy your holiday\n");
    int a = 5,b = 10;
    printf("a=%d,b=%d\n", a, b);
    printf("a=%#X,b=%#X\n", &a, &b);
    swap(a, b);
    swap1(&a, &b);
    getchar();
}

void swap(int a,int b){
    printf("a=%#X,b=%#X\n", &a, &b);
}

void swap1(int *a,int*b){
    printf("a=%#X,b=%#X\n", a, b);
    printf("swap1\n");
    printf("a=%d,b=%d\n", *a, *b);
    *a = 8;
    printf("a=%d   %#X\n", a,a);
}
