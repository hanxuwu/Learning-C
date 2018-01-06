

# include <stdio.h>
# include <string.h>


struct Student{
    int age;
    char sex;
    char name[100];
};

//void InputStudent(struct Student stu);
void InputStudent(struct Student *pstu);
void OutputStudent(struct Student ss);

int main(void){
    struct Student st;
    //无法修改主函数16行st的值
    //InputStudent(st);
    printf("%d\n",sizeof(st)); //108个字节
    InputStudent(&st);

    printf("%d %c % s\n", st.age, st.sex, st.name);
    
    OutputStudent(st);//对结构体变量输出,可以发送st的地址，也可以直接发送st的内容，
    //为了减少内存的耗费，也为了提高执行速度，推荐发送地址
    //OutputStudent(&st);

    return 0;
}

// 本函数无法修改主函数16行st的值,所以是错误的
/*
void InputStudent(struct Student stu){
    stu.age = 10;
    strcpy(stu.name, "PENY");
    stu.sex = 'M';
}
*/

//该函数可以实现对结构体赋值
void InputStudent(struct Student *pstu){
    pstu->age = 10;
    strcpy(pstu->name, "Peny");
    pstu->sex='M';
}

void OutputStudent(struct Student ss){
    printf("%d %c %s\n", ss.age, ss.sex, ss.name);
}
