/*


如何定义结构体


*/

# include <stdio.h>
//第一种
struct Student{
    int age;
    float score;
    char sex;
};

//第二种:不好！

struct Student2{
    int age;
    float score;
    char sex;
} st2;

int main(void){
    return 0;
}