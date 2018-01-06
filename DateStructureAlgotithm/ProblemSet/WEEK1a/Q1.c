/*
There is a 5-digit number that satisfies 4·abcde = edcba, 
that is, when multiplied by 4 yields the same number read backwards. 
Write a C-program to find this number.
*/

# include <stdio.h>

int main(void){
    int a;
    int b;
    int c;
    int d;
    int e;
    for(int i = 10000; i <=25000;i++)
    {
        a = i/10000;
        b = i/1000%10;
        c = i/100%10;
        d = i/10%10;
        e = i%10;
        //printf("%d\n", i);

        //printf("%d   %d\n", 4 * i, e * 10000 + d * 1000 + c * 100 + b * 10 + a);
        if((4*i)==(e*10000+d*1000+c*100+b*10+a)){
            printf("%d", i);
        }
    }
    return 0;
}