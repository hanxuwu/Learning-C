# include <math.h>
# include <stdio.h>

int reverse(int x);

int main(void){
    long x = 321111111111;
    long long test = pow(2, 31);
    printf("%d\n", test-1); //2147483647
    printf("%d\n", test); //-2147483648
    printf("%d\n", -test); //-2147483648

    int result;
    result=reverse(x);
    //int c = pow(2, 10);
    //printf("%d\n",c);
    printf("%d", result);
    return 0;
}
int reverse(int x) {
    //if (x>pow(2,31)-1|| x<-pow(2,31)) return x;
    long long c = pow(2, 31);
    printf("%d %d\n", c - 1, -c);
    if (x>c-1|| x<-c) return 0;
    else return x;
}