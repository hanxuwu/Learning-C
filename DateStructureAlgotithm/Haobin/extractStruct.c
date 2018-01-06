/*
赋值初始化
    定义的同时可以整体赋值
    如果定义完之后，则只能单个赋值
取出结构体变量中的每一个成员
    1.结构体变量名.成员名
    2. 指针变量名->成员名
结构体变量的运算
结构体变量和结构体变量指针作为函数参数传递的问题
*/

# include <stdio.h>

struct Student{
    int age;
    float score;
    char sex;
};

int main(void){
    struct Student st = {80, 66.6, 'F'};
    struct Student *pst = &st;

    pst->age = 88;
    st.score = 99.0;

    printf("%d %.1f %c", st.age, st.score, st.sex);

    return 0;

}

// 重要！！！  
//1.pst ->age 在计算机内部会被转换为(*pst).age ,这就是-> 的含义，这也是一种硬性规定
//2.所以 pst-> age 等价于  (*pst).age 也等价于 st.age
//3.我们之所以知道 pst->age 等于 st.age, 也是因为 pst -> age 是被转化成了 (*pst).age 来执行
//4. pst->age 的含义   pst  所指向的那个结构体变量中的age这个成员.
