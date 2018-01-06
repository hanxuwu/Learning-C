/*
(Dynamic arrays) 
Write a C-program that uses a dynamic array of   
unsigned long long int numbers (8 bytes, only positive numbers) 
to compute the n'th Fibonacci number, 
where n is given as command line argument. 
For example, ./fib 60 should result in 1548008755920. 
Hint: The placeholder  %lld  (instead of %d) 
can be used to print an  unsigned long long int. 
Remember that the Fibonacci numbers are defined as Fib(1) = 1, Fib(2) = 1 and Fib(n) = Fib(n-1)+Fib(n-2) for n≥3. 
*/
# include <stdio.h> 


unsigned long long int fib(int n){
    unsigned long long int a = 1;
    unsigned long long int b = 1;
    unsigned long long int t;
    unsigned long long int result=1;
    if(n <= 2) return 1;
    while ((n-2)!=0){
        result = a + b;
        a = b;
        b = result;
        n -= 1;
    }
    return result;
}



int main(int argc, char * argv[]){
    unsigned long long int array;
    array = fib(600);
    printf("%lld", array);
}