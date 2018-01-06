/*

算法：
    通俗定义：
        解题方法和步骤
    狭义定义:
        对存储数据的操作
    广义定义：
        广义的算法也叫泛型
        无论数据是如何存储的，对数据的操作都是一样的

*/

/*
数组
    优点：
        存取速度快
    缺点；
        需要一个连续的很大的内存
        插入和删除元素的效率很低

链表
    专业术语：
        头结点
            头结点的数据类型和首节点的类型是一模一样的
            头结点是首节点前面的那个结点
            头结点并不存放有效数据
            设置头结点的目的是为了方便对链表的操作
        头指针
            存放头结点地址的指针变量
        首节点
            存放第一个有效数据的结点
        尾结点
            存放最后一个有效数据的结点

    
    优点:
        插入删除元素效率高
        不需要连续的很大的内存
    缺点：
        查找某个元素的效率低
*/

# include <stdio.h>
# include <malloc.h>

//定义了一个链表结点的数据类型
struct Node{
    int data;//数据域
    struct Node *pNext;//指针域 递归思路  pNext 存放地址，存放 struct Node 变量地址
};

struct Node *CreateList(void);
void TraverseList(struct Node *pHead);

int main(void){
    struct Node * pHead;//指针变量，pHead用来存放链表头结点的地址

    pHead = CreateList();//创建链表
    TraverseList(pHead);//遍历链表
    getchar();
    getchar();
    return 0;
}

struct Node * CreateList(void)
{
    int len; //存放有效结点个数
    int i;
    int val;//用来临时存放用户输入的结点的值

    //分配了一个不存放有效数据的头结点
    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == pHead)
    {
        printf("no memory\n");
        exit(-1);
    }

    struct Node *pTail = pHead;
    pTail->pNext = NULL;
    printf("Please input the length of the linkedlist:");
    scanf("%d", &len);

    for (i = 0; i < len;i++)
    {
        printf("please input the %d  value\n", i+1);
        scanf("%d", &val);

        struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
        if(pNew == NULL)
        {
            printf("no memory\n");
            exit(-1);
        }

        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL; //记得末尾为空
        pTail = pNew;
    }
    return pHead;
}

// 输出链表
void TraverseList(struct Node* pHead){

    struct Node *cur;
    cur = pHead->pNext;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur = cur->pNext;
    }

    return;
}