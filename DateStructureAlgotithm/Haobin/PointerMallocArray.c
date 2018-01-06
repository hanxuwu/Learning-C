# include <stdio.h>

void f(int *arr,int len){
    for (int i = 0; i < len;i++){
        printf(" %d ", arr[i]);
    }
}


int main(void){

    int a[5]; //如果int 占4个字节，则本数组总共包含20个字节，每四个字节被当做了一个int 变量来使用
    int len;
    int *pArr;

    printf("Please input the number of elements");
    scanf("%d", &len);
    pArr = (int *)malloc(4 * len); //动态地构造了一个数组，该一维数组的长度是len
    pArr[2] = 15;
    pArr[0] = 1;
    printf("%d\n", pArr[2]);
    f(pArr, 5);
    return 0;
}
