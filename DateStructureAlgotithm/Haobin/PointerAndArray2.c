/*指针和数组
    指针和一维数组
        一维数组名 是一个指针常量

        下标和指针的关系

        指针变量的运算



    指针和二维数组


*/

# include <stdio.h>

int main(void){
    int a[5];//a 是数组名  5 是数组元素的个数  元素就是变量  
    //int a[3][4]; // 3行4列  a[0][0]  是第一个元素   a[i][j] 第 i+1行，j+1 列
    int b[5];

    //a=b  error  a是常量
    printf("%d\n", &a[0]);  //6422048
    printf("%#X\n", &a[0]); // 十六进制  #X         0X61FE20
    printf("%d\n", a);  // 6422048
    printf("%#X\n", a);  //0X61FE20
    return 0;
}