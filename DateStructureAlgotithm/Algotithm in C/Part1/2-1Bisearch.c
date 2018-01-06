# include <stdio.h>

int Bisearch(int arr[],int v,int l,int r){
    int m ;
    while (r>=l)
    {
        m = (l + r) / 2;
        if (arr[m] == v)
            return m;
        else if(arr[m]<v)
            l =m+ 1;            
        else
            r = m - 1;
    }
    return -1;
}

int main(int argc,char * argv[]){
    printf("Hello world!\n");
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int result;
    result = Bisearch(arr, 8, 0, 19);
    printf("%d", result);
    return 0;

    
}