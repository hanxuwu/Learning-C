/**
 * COMP9024 Assignment2 
 *
 * TASK1 : Pagerank
 *  
 * Date: 14/1/2018 
 *
 * Name: HANXU WU
 * 
 * ZID: 5148463
 * 
 * **/

# include <stdio.h>
# include <stdlib.h>
# include "pagerank.h"



int readfile(char * filename){
    FILE * fp;
    char words[MAX];

    if((fp=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Can't open file \" %s \" \n",filename);
        exit(1);
    }
    // puts("Enter words to add to the file;press the Enter");
    // puts("key at the beginning of a line to terminate.");
    // while(fgets(words, 200, stdin)!=NULL && words[0]!='\0') fgets(words, 200, stdin);
    // fprintf(fp,"%s ",words);
    // puts("file contents:");
    // rewind(fp); 
    while(fscanf(fp,"%s",words)==1) puts(words);
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n");
    return 0;

}


int main(int argc,char * argv[]){
    double d =(double)(atof)(argv[1]); // damping factor    atof:ascii to floating point numbers
    double diffPR = (double)(atof)(argv[2]); // difference in PageRank sum
    int maxIterations =(int)(atoi)(argv[3]);// maximum iterations   atoi:ascii to int numbers
    printf("%s %s %s\n",argv[1],argv[2],argv[3]);
    printf("%lf %lf %d\n",d,diffPR,maxIterations); //print the argument
    printf("%d\n",MAX); // if use include <>  could not find the include path
    readfile("collection.txt");

    return 0;
}