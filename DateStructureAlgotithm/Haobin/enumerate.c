/*
枚举
    什么是枚举
        把一个事物所有可能的取值一一列举出来
*/

# include <stdio.h>

//只定义了一个数据类型，并没有定义变量，该数据类型的名字是enum Weekday
enum WeekDay
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

enum WeekDay1
{
    Monda=6, Tuesda, Wednesda, Thursda, Frida, Saturda, Sunda
};

int main(void){
    enum WeekDay day=Wednesday;
    printf("%d\n", day); //2


    enum WeekDay1 day1=Wednesda;
    printf("%d\n", day1); //2
    return 0;
}