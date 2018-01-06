# include <stdio.h>

int main(void){
    int i = 5;
    int *p;
    int *q;
    p = &i;
    //*q = p; // error:assigning to 'int' from incompatible type 'int *'; dereference with *
    //*q = *p; // 数据类型一致，q中未赋值， error
    p = q; // 获取 q中的垃圾值,q赋给p，p也变成垃圾值
    printf("%d\n", *q); // 输出了你不能控制的一个内存单元中的数据
                        // q的空间是属于本程序的，所以本程序可以读写q的内容，但是如果q内部是垃圾值，则本程序不能读写*p 的内容
                        // 因为*q所代表的内存单元的控制权限并没有分配给本程序
                        // 指针最复杂的问题 是野指针问题
    return 0;
}

/*野指针
p,q,r 同时指向同一块动态分配内存的地址
free(p) 释放后  不能再free(q), 否则 程序崩溃！
一次都不 free  只分配不释放， 导致内存泄露：内存越用越少
多 free 直接崩溃    不free   越用越慢    

*/