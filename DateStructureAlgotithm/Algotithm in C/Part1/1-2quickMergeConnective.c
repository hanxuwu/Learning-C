# include <stdio.h>
# define N 10


int main(void){

    int i,j, p, q, id[N];

    for (i = 0; i < N;i++){
        id[i] = i;
        printf("%d ", id[i]);
    }
    printf("\n");
    while (scanf("%d %d", &p, &q) == 2) {// 当输入数据为二时
    for (i = p; i != id[i];i=id[i]);
    for (j = q; j != id[j];j=id[j]);
    if (i==j) continue;
    id[i] = j;
     for (i = 0; i < N;i++){
        printf("%d ", id[i]);
    }
    printf("\n");
    printf("%d %d\n", p, q);
    }

}

