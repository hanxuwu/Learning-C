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
# include "readfile.h"


Graph *createGraph(Graph *g,CollectionContext pCol){
    //printf("123");
    
    //Edge a={1,2};
    //insertEdge(*g, a);
    //showGraph(*g);
    return g;

}


int main(int argc,char * argv[]){
    double d=0.85;   // default damping factor 
    double diffPR=0.00001; // default difference in PageRank
    int maxIterations=1000;   // default maximum iterations
    //Graph g; // the Graph 
    
    if (argv[1]!=NULL && argv[2]!=NULL && argv[3]!=NULL){ // set the new argument
    d =(double)(atof)(argv[1]); // damping factor    atof:ascii to floating point numbers
    diffPR = (double)(atof)(argv[2]); // difference in PageRank sum
    maxIterations =(int)(atoi)(argv[3]);// maximum iterations   atoi:ascii to int numbers
    }

    printf("%s %s %s\n",argv[1],argv[2],argv[3]);
    printf("%lf %lf %d\n",d,diffPR,maxIterations); //print the argument
    printf("%d\n",MAX); // if use include <>  could not find the include path
    //readfile(&g,"collection.txt"); // reads data from a given collection of pages in the file 
    //g haven't been initialized,so transfer the address 
    //freeGraph(g);

    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("%d\n",p->nPages);// check the nPages
    printf("%d %d",p->urlName[0],p->urlName[1]); // check the array
    ReadUrlSection_1(11);
    printf("------------------------");
    printf("------SECTION2------");
    
    ReadUrlSection_2(11);
    //printf("%d",p2->nWords);
    // for(int i=0;i<p2->nWords;i++){
    //     printf("%s ",p2->words[i]);
    // }
    printf("-----------------------------------------");
    Graph g=newGraph(11);
    
    //Edge a={1,4};
    //insertEdge(g, a);
    freeGraph(g);
    //freeGraph(g);
   
    //showGraph(g);
    //createGraph(&g,p);
    return 0;
}