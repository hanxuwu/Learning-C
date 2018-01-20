/**
 * COMP9024 Assignment2 
 *
 * TASK2 : Inverted
 *  
 * Date: 20/1/2018 
 *
 * Name: HANXU WU
 * 
 * ZID: 5148463
 * 
 * use:  gcc -Wall -lm -Werror *.c  -o pagerank
 * 
 * **/

# include <stdio.h>
# include <string.h>
# include "readfile.h"
# include "InvertedIdx.h"
# include "DLListStr.h"

/*

   removing leading and trailing spaces,
   converting all characters to lowercase,
   remove the following punctuation marks, if they appear at the end of a word:
'.' (dot), ',' (comma), ';' (semicolon), ? (question mark)

*/
void normalise(UrlContext p2){
    
    printf("%d\n",p2->nWords);
     for(int i=0;i<p2->nWords;i++){ // traverse all the word in url context
        int foundchar=0; // find the word's end
        for(int lword=strlen(p2->words[i]);lword!=-1;lword--){ // travers all the char in each word
        //printf("%d",lword);
        //printf("%c\n",p2->words[i][lword]);
        if((foundchar==0)&&(p2->words[i][lword]!='?')&&(p2->words[i][lword]!='.')&&(p2->words[i][lword]!=',')&&(p2->words[i][lword]!=';')&&(p2->words[i][lword]!='\0')){
            foundchar=1; //end is the first char that not equal to punctuation marks,if find the end other no need to delete
        } 
        if(p2->words[i][lword]>='A'&&p2->words[i][lword]<='Z'){//converting all characters to lowercase
            p2->words[i][lword]+=32;       
        }
        else if((p2->words[i][lword]=='?'||p2->words[i][lword]=='.'||p2->words[i][lword]==','||p2->words[i][lword]==';')&&(foundchar==0))
            p2->words[i][lword]='\0'; // if the end char is  (dot), ',' (comma), ';' (semicolon), ? (question mark) the reassignment the end
        }
        printf("%s ",p2->words[i]);
    }
}

int main(int argc,char * argv[]){

    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("the name of the collection in main function\n");
    for(int i=0;i<p->nPages;i++){
        printf("%d ",p->urlName[i]);// check the stored integer name
    }
    printf("\n");
    printf("------SECTION2------");

    // nomolize all the urlcontext
    UrlContext p2;
    for(int i=0;i<p->nPages;i++){
        p2=ReadUrlSection_2(p->urlName[i]); // read the url file section2
        normalise(p2);
    }
    


    
}