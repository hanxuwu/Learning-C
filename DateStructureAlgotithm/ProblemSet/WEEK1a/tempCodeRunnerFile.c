# include<stdio.h>
# define SWAP(a,b,c) ((c=a),(a=b),(b=c))

void permutation(char array[], int index, int size);

int main(void){
    int size = 6;
    char array[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    permutation(array[6],0, size);
}

void permutation(char array[],int index,int size){
    int i,temp;
    if(index==size){
        for (i = 0; i < size;i++){
            printf("%c", array[i]);
        }
        printf("\n");
    }else{
        for (j = index; j < size;j++){
            SWAP(array[j], array[index], temp);
            permutation(array[], index + 1, size);
            SWAP(array[j], array[index], temp);
        }
    }
}
