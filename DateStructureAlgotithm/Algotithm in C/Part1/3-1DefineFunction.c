# include <stdio.h>

int lg(int);

int main(int argc,char*argv[]){
    int a = 64;
    int result;
    result = lg(a);
    printf("%d", result);
}

//write myself
int lg(int a){
    int count = 0;
    while(a>1){
        a /= 2;
        printf("%d   %d\n", count, a);
        count += 1;
    }
    return count;
}

//write by




