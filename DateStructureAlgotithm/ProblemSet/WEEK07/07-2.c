# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# define MAX_TEXT_LENGTH 1024
# define MAX_PATTERN_LENGTH 128
# define MAX_ALPHABET_LENGTH 128
# define TEXT_FORMAT_STRING "%[^\n]%*c"
# define PATTERN_FORMAT_STRING "%[^\n]%*c"
# define ALPHABET_FORMAT_STRING "%[^\n]%*c"

# define MIN(x,y) ((x<y)?x:y)  //tenary operator cond ? t1 :t2
                                // => evaluates to t1 if (cond) not equal to 0,else to t2

int boyerMoore(char * text,char *pattern,int *L){
    int n= strlen(text);
    int m= strlen(pattern);

    int i = m-1;
    int j = m-1;
    do{
        if(text[i] == pattern[j]){
            if(j==0){
                return i;
            }else{
                i--;
                j--;
            }
        }else {     // character jump
            i = i+m-MIN(j,1+L[(int)text[i]]);
            j= m-1;
        }
    }while (i<n);
    return -1;    // no match
}

int *lastOccurrenceFunction(char *pattern,char *alphabet){
    int *L = malloc(MAX_PATTERN_LENGTH *sizeof(int));
    assert(L!=NULL);

    int i,s = strlen(alphabet);
    for(i=0;i<s;i++)      // for all chars in the alphabet
        L[(int)alphabet[i]]=-1; // ...initialise L[] to -1
    int m = strlen(pattern);
    for(i=0;i<m;i++)
        L[(int)pattern[i]]=i;   //set L[]

    return L;
}

int main(void){
    char T[MAX_TEXT_LENGTH];
    char P[MAX_PATTERN_LENGTH];
    char S[MAX_ALPHABET_LENGTH];

    printf("Enter alphabet:");
    scanf(ALPHABET_FORMAT_STRING,S);
    printf("Enter text:");
    scanf(TEXT_FORMAT_STRING,T);
    printf("Enter pattern:");
    scanf(PATTERN_FORMAT_STRING,P);
    putchar('\n');

    int *L = lastOccurrenceFunction(P,S);
    int i,s = strlen(S);
    for(i=0;i<s;i++){
        printf("L[%c]=%d\n",S[i],L[(int)S[i]]);
    }

    int match = boyerMoore(T,P,L);
    free(L);
    if (match >-1)
        printf("\nMatch found at position %d.\n",match);
    else
        printf("\nNo match.\n");

    return 0;
}
