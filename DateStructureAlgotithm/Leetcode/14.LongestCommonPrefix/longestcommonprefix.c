# include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i;
    int max=0;
    char temp;
    char *result = strs[0];
    if (strsSize==0) return "";
    while(1){
    for(i=0;i<strsSize;i++){
        temp=strs[0][max];
        if(strs[i][max]!=temp) 
            {result[max]=0; return result;} 
    }
        
    max++;
    if (max==(strsSize+1)) return result;
    
    }
}


int main (void){

    char * array[3] = {"abcd","abc","abcdef"};
    char **strs = array;
    char * answer;
    answer = longestCommonPrefix(strs,3);
    printf("%s",*answer);  
}