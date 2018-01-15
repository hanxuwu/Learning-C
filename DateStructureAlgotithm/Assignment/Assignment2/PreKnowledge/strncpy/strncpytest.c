# include <stdio.h>
# include <string.h>

// Use strncpy copy the string from the specific number

//gcc -Wall -Werror strncpytest.c -o test

int main(int argc,char * argv[]){

    char * a = "abcdefg";
    char b[1000];
    strncpy(b,a+2,10); // 从a第二位开始截取后面10位，保存到b
    printf("%s",b);//cdefg%  
}