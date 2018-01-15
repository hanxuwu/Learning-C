# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc,char * argv[]){
    FILE *fp;
    char text[1000]; 
    //char number[10]="!!!!!!!!!!";
    char buf[100];//method 1
    //char buf;//method 2
    int i=0;
    int pagenum[100];

    if((fp=fopen("a.txt","r"))==NULL){
        fprintf(stderr,"Can't open the file");
        exit(1);
    }

    while(fscanf(fp,"%s",text)==1){
        //strncpy(number,text,100);
        //printf("@%s\n",number);
        //puts(number);

        //sscanf(text,"%s",buf); //max value 2147483647

        // Method 1
        sscanf(text,"%s",buf); //max value 2147483647          
        printf("@%d\n",(atoi)(buf+3));
        pagenum[i] = (atoi)(buf+3);
        i++;
        

        /*Method 2
        sscanf(text,"%s",&buf); //max value 2147483647          
        printf("@%d\n",(atoi)(&buf+3));
        pagenum[i] = (atoi)(&buf+3);
        i++;
        */
        
    }
    printf("--------------------------------\n");
    for(int c=0;c<i;c++)
    printf("%d\n",pagenum[c]);
    return 0;

}