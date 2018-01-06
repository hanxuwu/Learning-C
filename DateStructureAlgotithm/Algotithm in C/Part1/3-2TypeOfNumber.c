# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef int Number;
Number randNum(){
    //srand(time(0));
    //srand(2);
    return 10*rand()/(RAND_MAX+1);
    //return rand();
}

typedef float Numberfloat;
Numberfloat randNum1(){
    return 1.0 * rand() / RAND_MAX;
}






int main(int argc,char * argv[]){
    int i;
    //int N = atoi(argv[1]);
    int N = 10;
    float m1 = 0.0, m2 = 0.0;
    Number x;
    Numberfloat y;
    for (i = 0; i < N;i++){
        x = randNum();
        printf("randint %d\n", x);
        y = randNum1();
        printf("randint %f\n", y);

        m1 += ((float)x) / N;
        m2 += ((float)x * x) / N;
    }
    printf("     Average:%lf\n", m1);
    printf("Std.deviation: %lf\n", sqrt(m2 - m1 * m1));
}


