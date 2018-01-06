/*
(Elementary data structures)
        Define a data structure to store all information of a single ride with the Opal card.Here are two sample records :

    Transaction number
    / Date time / Mode/ Detail / Journey number/Fee Applied/Fare/Discount/Amount/

You may assume that individual stops 
(such as "Anzac Pde D opp UNSW") require no more than 31 characters. 
Determine the memory requirements of your data structure, 
assuming that each integer and floating point number takes 4 bytes. 
If you want to store millions of records, 
how would you improve your data structure? 

*/

# include <stdio.h>

typedef struct{
    int day, month, year;
} DateT;

typedef struct{
    int hour, minute;

} TimeT;

typedef struct{
    int Transaction;
    char weekday[4];
    DateT date;
    TimeT time;
    char mode;
    char from[32], to[32];
    int journey;
    char faretext[12];
    float fare, discount, amount;
} JourneyT;
