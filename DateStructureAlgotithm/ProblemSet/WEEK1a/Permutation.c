#include<stdio.h>
#define SWAP(a,b,c) ((c)=(a),(a)=(b),(b)=(c))
/*
int count = 0;
void swap(char *p1,char *p2)
{
char t=*p1;
*p1=*p2;
*p2=t;
}
*/

void permutation(char a[],int index,int size)
{
    int t;
    if(index==size)
        {
            count += 1;
            for(int i=0;i<size;i++)
            
            printf("%c ",a[i]);
            printf("\n");
            
        }else{
            for(int j=index;j<size;j++){
                //swap(&a[j],&a[index]);
                SWAP(a[j], a[index],t);
                permutation(a,index+1,size);//此处用到递归思想
                SWAP(a[j], a[index],t);
                //swap(&a[j],&a[index]);
                }
            }
}

int main()
{
int n=6;

char a[6]={'a','b','c','d','e','f'};
permutation(a,0,n);
printf("%d", count);
return 0;
}