# include <stdio.h>
# include <string.h>

char * normalizeString(char * word){
    int foundchar=0;
    for(int lword=strlen(word);lword!=-1;lword--){ // travers all the char in each word
        //printf("%d",lword);
        //printf("%c\n",p2->words[i][lword]);
        if((foundchar==0)&&(word[lword]!='?')&&(word[lword]!='.')&&(word[lword]!=',')&&(word[lword]!=';')&&(word[lword]!='\0')){
            foundchar=1; //end is the first char that not equal to punctuation marks,if find the end other no need to delete
        } 
        if(word[lword]>='A'&&word[lword]<='Z'){//converting all characters to lowercase
            word[lword]+=32;       
        }
        else if((word[lword]=='?'||word[lword]=='.'||word[lword]==','||word[lword]==';')&&(foundchar==0))
            word[lword]='\0'; // if the end char is  (dot), ',' (comma), ';' (semicolon), ? (question mark) the reassignment the end
        }
        return word;

}

int main(void){
    
    char a[] ="AbC,dEf;;;???....,,,,,,,,,,,";
    normalizeString(a);
    printf("%s",a);
}