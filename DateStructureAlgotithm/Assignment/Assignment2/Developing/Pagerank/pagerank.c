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
# include <assert.h>
# include "pagerank.h" // Constant Argument
# include "Graph.h" //  Refer to Lecture3 Resource written by Ashesh Mahidadia
# include "readfile.h"

/*

Create the Linked list Graph from the file

*/
Graph *createGraph(Graph *g,CollectionContext pCol){
    assert(NULL!=pCol);
    *g = newGraph(pCol->nPages); // allocate memory for Graph
    
    for(int pIndex=0;pIndex<pCol->nPages;pIndex++){ // traverse all the pages
        UrlContext temp=ReadUrlSection_1(pCol->urlName[pIndex]); // tempory context
        if(temp->nUrl==0) continue; // if there is no page;in that page continue
        else{
            for(int uIndex=0;uIndex<temp->nUrl;uIndex++){// traverse all the links
                int findindex;
                for(findindex=0;findindex<pCol->nPages;findindex++){ // find the index of the linked url
                    if(pCol->urlName[findindex]==temp->coUrlName[uIndex]){ //                 
                        Edge tempEdge={pIndex,findindex}; //create the edge
                        insertEdge(*g,tempEdge);  
                        break;
                    }
                }
                
            
            }
        }
    }
    showGraph(*g);
    return g;

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
    //readfile(&g,"collection.txt"); // reads data from a given collection of pages in the file 
    //g haven't been initialized,so transfer the address 
    //freeGraph(g);

    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("the name of the collection in main function\n");
    for(int i=0;i<p->nPages;i++){
        printf("%d ",p->urlName[i]);// check the stored integer name
    }
    printf("\n");
    // ReadUrlSection_1(11);
    printf("------SECTION2------");
    UrlContext p2;
    p2=ReadUrlSection_2(11);
    printf("%d",p2->nWords);
     for(int i=0;i<p2->nWords;i++){
         printf("%s ",p2->words[i]);
    }
    printf("-----------------------------------------");
    createGraph(&g,p);
    return 0;
}