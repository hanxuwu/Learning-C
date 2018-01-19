# include <stdio.h>

int main(void){
    double a =5;
    double b =10;
    int c=0;
    while(c<10 &&b>=a){
        c++;
        b--;    
        printf("a>b:%s\n",a>b?"True":"False");
    
    }
    printf("%f %f",a,b);
    return 0;
}