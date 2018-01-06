 
int main(void){
    int len;
    struct Student *pArr;

    // 动态构造一维数组

    printf("Please input the number of students:\n");
    printf("len=");
    scanf("%d", &len);
    pArr = (struct Student *) malloc(len * sizeof(struct Student));