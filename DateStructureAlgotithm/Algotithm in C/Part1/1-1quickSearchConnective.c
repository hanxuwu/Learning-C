/*

连通问题查找算法

*/


# include <stdio.h>
# define N 10

int main(void){
    int i, p, q, t, id[N]; //p q 输入值，t 比较值
    for (i = 0; i < N;i++){ // 数组建立初值
        id[i] = i;
    printf("%d\n", id[i]);    
    }

    //while (scanf("%d %d\n", &p, &q) == 2) // 加\n 需要输入两遍
    while (scanf("%d %d", &p, &q) == 2) // 当输入数据为二时
    
    {

        
   
    if (id[p] == id[q])
        continue;
    for (t = id[p], i = 0; i < N; i++)
        /*
        if (id[i] == t){        //加大括号，if 成立执行后面两句
            id[i] = id[q];
            printf("%d %d\n", p, q);
        }
        */    

        if (id[i] == t)  id[i] = id[q];
        printf("%d %d      ", p, q);
        
    for (i = 0; i < N;i++){
        printf("%d ", id[i]);    

    }
     printf("\n");
    }


    
}