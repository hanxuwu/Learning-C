# include <stdio.h>

// Test GCC

/*

GCC两种写法

gcc a.c -o a
或者
gcc -o a a.c  

*/

/*

gcc a.c -o a.bxb   generate a.bxb

gcc -o a.exe a.c   geberate a.exe

then use ./a.exe     execute the code


*/
int main(void){
    printf("This is file a\n");
    return 0;
}
/*

% gcc a.c -o a

% ./a
This is file a

% make
make: *** No targets specified and no makefile found.  Stop.

*/