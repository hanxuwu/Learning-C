# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct Point{
    int x;
    int y;
}Point;

float distance(Point, Point);


float distance(Point a,Point b){
    //printf("%d %d %d %d\n", b.y, a.y, b.x, a.x);
    printf("%f %f\n",pow((b.y - a.y),2),pow((b.x - a.x),2));// Pow 表示平方
    //return sqrt((b.y - a.y)^2 + (b.x - a.x)^2); ^2 不是平方

    float dx = b.x - a.x;
    float dy = b.y - a.y;
     printf("%f %f\n",dx * dx, dy * dy);
     printf("%f\n", sqrt(10.0));
     return sqrt(dx * dx + dy * dy);

}


int main(int argc,char * argv[]){
    printf("%s\n", argv[0]); // display the file location

    Point a, b;
    a.x = 2;
    a.y = 1;
    b.x = 3;
    b.y = 4;
    printf("%f", distance(a, b));
}