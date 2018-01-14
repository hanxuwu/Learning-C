# include <stdio.h>
# include <a.h> // 使用 gcc -o a a.c  找不到   fatal error: a.h: No such file or directory
// #include "a.h" // // 可以使用 gcc -o a a.c   可以使用

// 如果使用了include<>
// 使用 gcc -o b a.c -I ./
// 或者 gcc -I ./ -o c a.c   形式 搜索当前文件目录
int main(void){
    printf("%d",MAXII);
}