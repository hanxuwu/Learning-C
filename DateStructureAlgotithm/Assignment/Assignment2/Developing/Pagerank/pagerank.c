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
 *use:  gcc -Wall -lm -Werror *.c  -o pagerank
 * 
 * **/

# include <stdio.h>
# include <stdlib.h>
# include "pagerank.h" // Constant Argument
# include "Graph.h" //  Refer to Lecture3 Resource written by Ashesh Mahidadia
# include "list.h"

// typedef struct PageGraphVar{
//     int nPages;
//     int *urlNameArr;
// };







int readfile(Graph *g,char * filename){ // read the file add create the Graph
    FILE * fp;
    char words[MAX]; // store the vertex name
    int nPages=0; // number of the Pages (Vertices)
    char buf[100];// buf to store the sscanf 
    int *urlName; // // store the digit name of the url
    

    if((fp=fopen(filename,"r"))==NULL){ // check the file  could be open or not
        fprintf(stderr,"Can't open file \" %s \" \n",filename);
        exit(1);
    }
    
    // Count the number of url
    while(fscanf(fp,"%s",words)==1) {  //read the body of a section
        puts(words);   // print the file content
        //sscanf(words,"%s",buf); // save the each section to buffer
        //urlName[nPages]=(atoi)(buf+3); //keep the interger name of the url then convert to int
        nPages++; // count the number of url
        };
    printf("\nafter first count the number then rewind to build array\n\n"); 
    printf("the words %s\n",words);
    // store the integer name of the url
    urlName = malloc(nPages*sizeof(int)); // create the array to store the integer urlName
    rewind(fp);// from the file start
    int index=0; // array index;
    while(fscanf(fp,"%s",words)==1) {  //read the body of a section
        puts(words);   // print the file content
        sscanf(words,"%s",buf); // save the each section to buffer
        urlName[index]=(atoi)(buf+3); //keep the interger name of the url then convert to int
        index++; // count the number of url
        };
    
    
    printf("number of pages in %s file  is %d  \n",filename,nPages);
    printf("there name is\n");
    for (int i=0;i<nPages;i++)
    printf("%d ",urlName[i]);
    *g =newGraph(nPages); // create the graph
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    return 0;
}


int main(int argc,char * argv[]){
    double d=0.85;   // default damping factor 
    double diffPR=0.00001; // default difference in PageRank
    int maxIterations=1000;   // default maximum iterations
    Graph g; // the Graph 
    
    if (argv[1]!=NULL && argv[2]!=NULL && argv[3]!=NULL){ // set the new argument
    d =(double)(atof)(argv[1]); // damping factor    atof:ascii to floating point numbers
    diffPR = (double)(atof)(argv[2]); // difference in PageRank sum
    maxIterations =(int)(atoi)(argv[3]);// maximum iterations   atoi:ascii to int numbers
    }

    printf("%s %s %s\n",argv[1],argv[2],argv[3]);
    printf("%lf %lf %d\n",d,diffPR,maxIterations); //print the argument
    printf("%d\n",MAX); // if use include <>  could not find the include path
    readfile(&g,"collection.txt"); // reads data from a given collection of pages in the file 
    //g haven't been initialized,so transfer the address 
    //freeGraph(g);

    return 0;
}