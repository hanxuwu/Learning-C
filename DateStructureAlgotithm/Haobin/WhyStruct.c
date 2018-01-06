# include <stdio.h>
/*
为什么需要结构体？
    为了表示一些复杂的事物，而普通基本类型无法满足实际要求
什么叫结构体
    把一些基本类型数据组合在一起形成一个新的数据类型，这个叫做结构体

*/

struct Student{
    int age;
    float score;
    char sex;
};

int main(void){

/*
    int age;
    float score;
    char sex;
    int age2;
    float score2;
    char sex2;
*/
struct Student st = {80, 66.6, 'F'};
printf("%d,%.1f,%c", st.age,st.score,st.sex);
return 0;
}