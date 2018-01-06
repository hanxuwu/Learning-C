/*
(Elementary control structures) 
Write a C-function that takes a positive integer n as argument and outputs a series of numbers according to the following process,
until 1 is reached:
if n is even, then n ← n/2 
if n is odd, then n ← 3*n+1 
*/

# include <stdio.h>
# define SWAP(a,b,c) ((c=a),(a=b),(b=c))

void f(int n){
    while(n!=1){
        if(n%2==0){
            n /= 2;
            printf("%d ", n);
        }else{
            n = 3 * n + 1;
            printf("%d ", n);
        }
    }
}

int fib(int a){
    int first = 1, second = 1;
    int fibnumber;
    if (a<=2){
        fibnumber =1;
    }else{
   
    for (int i = 2; i <a;i++){
        fibnumber = first + second;
        first = second;
        second = fibnumber;
    }
    }
    printf("\n%d", fibnumber);
    return fibnumber;
}


int main(void){
    int n;
    f(3);

    int f;
    f = fib(4);

    return 0;
}