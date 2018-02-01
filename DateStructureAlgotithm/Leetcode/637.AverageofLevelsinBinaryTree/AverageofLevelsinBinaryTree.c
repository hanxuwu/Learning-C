# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

void traverse(int *a,int i,int **b){
    for(int i=0;i<10;i++){
        (*b)[i] = a[i];
    }

}

double* averageOfLevels(void) {
    double * new = (double *)malloc(300* sizeof(double));
    //int count=0;
    //traverTree(root,0,count,&new);
    new[0]=15.000000;
    new[1]=15.000000;
    new[2]=15.000000;
    return new;
    //return new[3];
        
}

int main(void){
    int a[10]={1,2,3,4,5,6,7,8,9};
    int * new=malloc(10*sizeof(int));
    traverse(a,0,&new);
    for(int i=0;i<10;i++){
        printf("%d",new[i]);
    }
    printf("\n");
    //double b[]={5.0,4.0,3.0,2.0,1.0};
    double * new1 = malloc(10* sizeof(double));
    new1[0]=9.0;
    printf("%f",new1[0]);
    double * new2=averageOfLevels();
    printf("%f",new2[0]);
    printf("%f",new2[1]);
    printf("%f",new2[2]);
    return 0; 

}