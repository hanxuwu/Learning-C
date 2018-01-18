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

double d=0.85;   // default damping factor 
double diffPR=0.00001; // default difference in PageRank
int maxIterations=1000;   // default maximum iterations


/*

pagerank structure

*/
typedef struct PrNodeRep{
    int urlIndex; // Index in the collection file
    int outdegree; //  out degrees (number of out going links) 
    double PrVal; // PageRank Value
}PrNodeRep;

typedef PrNodeRep * PrNode; // pointer to PrNode

typedef struct PrStructRep{ // PageRank structure
    int nUrl; // number of PrNode
    PrNode * PrArr; // Array store the PrNode
}PrStructRep;

typedef PrStructRep * PrStruct; // Pointer to Pagerank structure 

/*

Initial the PrNode

*/
static PrNode createPrNode(int urlIndex,double initPrVal){
    PrNode new = malloc(sizeof(PrNodeRep));
    assert(NULL!=new);
    new->urlIndex =urlIndex;
    new->outdegree=0; //start with 0;
    new->PrVal=initPrVal; // the initial should be 1/N
    return new;
}

/*

Initialize the Prstruct structure

*/

PrStruct createPrstruct(CollectionContext p){
    int N = p->nPages; // The total pages of the graph
    PrStruct prs = malloc(sizeof(PrStructRep)); // allocate memory for Pagerank struct
    assert(NULL!=prs);
    prs->PrArr = malloc(N*sizeof(PrNode)); // allocate memory to store the address of the node
    assert(NULL!=prs->PrArr);
    double InitPrVal = 1.0/ N; // initial PageRank Value
    //initialize the PrNode and save it to structure
    for(int urlIndex=0;urlIndex<N;urlIndex++){
        prs->PrArr[urlIndex]=createPrNode(urlIndex,InitPrVal); // TODO:count the outdegree
    }
    return prs;
}







/*

RankPage algorithm

*/
PrStruct Pagerank(Graph *g,PrStruct *prs){
    int N = (*g)->nV; // The total pages of the graph
    printf("%lf %lf %d",d,diffPR,maxIterations);
    double damping_value = (1.0 - d) / N; // (1-x)/N

    for(int urlIndex=0;urlIndex<N;urlIndex++){ //traverse all the pages
            printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);
            printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);
            printf("^%lf \n",(*prs)->PrArr[urlIndex]->PrVal);
        }

    for(int iter=0;iter<maxIterations;iter++){
        double change = 0;// to check the differces
        

    }
    
    return prs;

}









/*

Create the Linked list Graph from the file

*/
Graph *createGraph(Graph *g,CollectionContext pCol,PrStruct *prs){
    assert(NULL!=pCol);
    *g = newGraph(pCol->nPages); // allocate memory for Graph
    
    for(int pIndex=0;pIndex<pCol->nPages;pIndex++){ // traverse all the pages
        UrlContext temp=ReadUrlSection_1(pCol->urlName[pIndex]); // tempory context
        if(temp->nUrl==0) {; // if there is no page point to the page will pointer to every page
            for(int allindex=0;allindex<pCol->nPages;allindex++){ // traverse all the page 
                    if(allindex!=pIndex){ // it point to every page except itself                 
                        Edge tempEdge={pIndex,allindex}; //create the edge
                        insertEdge(*g,tempEdge);
                        (*prs)->PrArr[pIndex]->outdegree++;   // count the outdegree
                    }else continue;
                }        
        }
        else{
            for(int uIndex=0;uIndex<temp->nUrl;uIndex++){// traverse all the links
                int findindex;
                for(findindex=0;findindex<pCol->nPages;findindex++){ // find the index of the linked url
                    if(pCol->urlName[findindex]==temp->coUrlName[uIndex]){ //                 
                        Edge tempEdge={pIndex,findindex}; //create the edge
                        insertEdge(*g,tempEdge);
                        (*prs)->PrArr[pIndex]->outdegree++;   // count the outdegree  
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
    PrStruct prs=createPrstruct(p);
    //printf("----------------------------");
    //printf("\ntest outdegree %d\n",prs->PrArr[0]->outdegree);
    createGraph(&g,p,&prs);
    Pagerank(&g,&prs);
    return 0;
}