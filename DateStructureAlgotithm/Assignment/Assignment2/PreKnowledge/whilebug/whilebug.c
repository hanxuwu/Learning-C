# include <stdio.h>
double diffPR=5;
int maxIterations=10;

int main(void){
    int iter=0;
    double diff=diffPR;   
    while((iter<maxIterations) && (diff>=diffPR)){
        iter++;
        diff--;
        double diff = 0;// to check the differces        
        printf("\ndiff>=diffPR:%s",diff>=diffPR?"True":"False"); 
        

    }
}