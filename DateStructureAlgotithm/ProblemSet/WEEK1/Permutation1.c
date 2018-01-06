#include"stdio.h"
#define SWAP(a,b,c) ((c)=(a),(a)=(b),(b)=(c))
int count = 0;
void perm(char *list,int i,int n);
int main()
{
    char arry[6]={'a','b','c','d','e','f'};
    perm(arry,0,6);
    printf("%d", count);
    return 0;
}

void perm(char *list,int i,int n)
{
    int j,temp;
    if(i==n)
    {
        count += 1;
        for(j=0;j<n;j++){
            printf("%c",list[j]);
        }
        printf("\n");
    }
    else
    {
        for(j=i;j<n;j++){
            SWAP(list[i],list[j],temp);
            perm(list,i+1,n);
            SWAP(list[i],list[j],temp);
        }
    }
}