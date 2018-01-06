# include <stdio.h>
void swap(int *, int *);

void swap(int *p,int *q){
    int t;
    t = *p;
    *p = *q;
    *q = t;
}


int main(void){

    int a = 3;
    int b = 5;

    swap(&a,&b);
    printf("a=%d,b=%d", a, b);
}
