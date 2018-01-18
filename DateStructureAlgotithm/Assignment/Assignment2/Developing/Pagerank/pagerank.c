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
# include <math.h> 
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

typedef struct PrNodeRep * PrNode; // pointer to PrNode

typedef struct PrStructRep{ // PageRank structure
    int nUrl; // number of PrNode
    PrNode * PrArr; // Array store the PrNode
}PrStructRep;

typedef struct PrStructRep * PrStruct; // Pointer to Pagerank structure 

typedef struct IncidenceRep{ // store the Incidence urlname
    List * incidence;
    int * size; // size of each array
}IncidenceRep;

typedef struct IncidenceRep * Incidence;

Incidence gettheincidence (Graph *p,PrStruct *prs){
    Incidence new = malloc(sizeof(IncidenceRep));
    assert(NULL!=new);
    new->size =malloc((*p)->nV * sizeof(int));
    assert(NULL!=new->size);
    new->incidence =malloc((*p)->nV * sizeof(List));

    
    for(int i=0;i<(*p)->nV;i++){ // initial the array  which will store the size
        printf("%d",(*p)->nV);
        printf("%d",i);
        new->size[i]=0;
        new->incidence[i]=NULL;
        printf("***%d\n",new->size[i]);        

    }

// count the incidence
    for(int urlIndex=0;urlIndex<(*p)->nV;urlIndex++){
        Node* a = (*p)->edges[urlIndex]; // there is no node has no outdegree
        
        for(int i=0;i<(*prs)->PrArr[urlIndex]->outdegree;i++){
            printf("@@%d   ",a->v);
            List temp=insertLL(new->incidence[a->v],urlIndex); // pit insertLL insert ahead，after insert you should assign the head of list 
            new->incidence[a->v]=temp; // reassign the head of each list
            
            new->size[a->v]++; // count the size of each list
            a=a->next; //move to next          
        }        
        
    }
    for(int urlIndex=0;urlIndex<(*p)->nV;urlIndex++){
    printf("***%d\n",new->size[urlIndex]); // incidence size of each line
    showLL(new->incidence[urlIndex]); 
    }
    return new;
}








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

    

    for(int iter=0;iter<maxIterations;iter++){    
        double change = 0;// to check the differces
        for(int urlIndex=0;urlIndex<N;urlIndex++){ //traverse all the pages
            //showLL((*g)->edges[urlIndex]);
            double rank = 0;
            Node* a = (*g)->edges[urlIndex]; // there is no node has no outdegree
            double current_rankval =(*prs)->PrArr[urlIndex]->PrVal;
            for(int i=0;i<(*prs)->PrArr[urlIndex]->outdegree;i++){
                //printf("@@%d   ",a->v);
                rank+=d*((*prs)->PrArr[a->v]->PrVal/(*prs)->PrArr[a->v]->outdegree);
                a=a->next;          
            }
            rank+=damping_value;
            change+=fabs(current_rankval-rank);
            (*prs)->PrArr[urlIndex]->PrVal=rank;
                     
            
            
            //printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);
            //printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);
            //printf("^%lf \n",(*prs)->PrArr[urlIndex]->PrVal);
        }
        if (change < diffPR) break;
        

    }
    for(int urlIndex=0;urlIndex<N;urlIndex++){
    printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);
    printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);
    printf("^%.7f \n",(*prs)->PrArr[urlIndex]->PrVal);
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
    gettheincidence(&g,&prs);
    //Pagerank(&g,&prs);
    return 0;
}