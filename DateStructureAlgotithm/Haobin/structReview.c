# include <stdio.h>

struct Student{
    int age;
    char sex;
    char name[100];
}; //  分号不能省略


int main(void){

    struct Student st = {20, 'F', "LOVE"};
    struct Student *pst = &st;

    printf("%d %c %s\n", st.age, st.sex, st.name);
    printf("%d %c %s\n", pst->age, pst->sex, pst->name);

}