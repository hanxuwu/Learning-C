# include <stdio.h>

// ATTENTION : This method only works in Leetcode
/*
C99（6.7.8.32）：On the other hand, the declarationchar *p = "abc";defines p with type ‘‘pointer to char’’ and initializes it to point to an object with type ‘‘array of char’’ with length 4 whose elements are initialized with a character string literal. If an attempt is made to use p to modify the contents of the array, the behavior is undefined.



*/
char* longestCommonPrefix(char** strs, int strsSize) {  
    char* str=strs[0];  
    int i,j;  
    if(strsSize==0)return "";  
    for(i=1;i<strsSize;i++){  
        j=0;  
        while(str[j] && strs[i][j] && str[j]==strs[i][j])j++;  
        str[j]=0;   // in most case ,we could not modify the string;
    }  
    return str;  
}  


int main (void){

    char * array[3] = {"abcd","abc","abcdef"};
    char **strs = array;
    char * answer;
    answer = longestCommonPrefix(strs,3);
    printf("%s",*answer);  
}