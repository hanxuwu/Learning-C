/*
举例：
    动态构造存放学生信息的结构体数组
        动态构造一个数组,存放学生信息

*/

# include <stdio.h>
# include <malloc.h>

struct Student{
    int age;
    float score;
    char name[100];
};
 
int main(void){
    int len;
    struct Student *pArr,t;

    // 动态构造一维数组

    printf("Please input the number of students:\n");
    printf("len=");
    scanf("%d", &len);
    pArr = (struct Student *)malloc(len * sizeof(struct Student));

    for (int i = 0; i < len;++i){
        printf("please input the %d info:\n", i + 1);

        printf("age=\n");
        scanf("%d", &pArr[i].age); //scanf 后只能直接输入 字符 

        printf("name=\n");
        scanf("%s", pArr[i].name);

        printf("score=\n");
        scanf("%f", &pArr[i].score);
  
    }

    // 排序

    for (int i = 0; i < len - 1;++i)
    {
        for (int j = 0; j < len - 1 - i;++j)
        {
            if(pArr[j].score>pArr[j+1].score) //>升序    <降序
            {
                t = pArr[j];
                pArr[j]=pArr[j+1];
                pArr[j + 1] = t;
            }
        }
    }

        //输出
        printf("\nprint all the info\n");
    for (int i = 0; i < len;++i){
        printf("the %d info:\n", i + 1);
       
        printf("age=%d\n", pArr[i].age);
        printf("name=%s\n", pArr[i].name);
        printf("score=%f\n", pArr[i].score);
    }

    return 0;
}