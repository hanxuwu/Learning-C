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
 * use:  gcc -Wall -lm -Werror *.c  -o pagerank
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

    int i;
    for(i=0;i<(*p)->nV;i++){ // initial the array  which will store the size
        printf("%d",(*p)->nV);//TODO:
        printf("%d",i);//TODO:
        new->size[i]=0;
        new->incidence[i]=NULL;
        printf("***%d\n",new->size[i]);   //TODO:     

    }

// count the incidence
    int urlIndex;
    for(urlIndex=0;urlIndex<(*p)->nV;urlIndex++){
        Node* a = (*p)->edges[urlIndex]; // there is no node has no outdegree
        int i;
        for(i=0;i<(*prs)->PrArr[urlIndex]->outdegree;i++){
            printf("@@%d   ",a->v);//TODO: 
            List temp=insertLL(new->incidence[a->v],urlIndex); // pit insertLL insert ahead，after insert you should assign the head of list 
            new->incidence[a->v]=temp; // reassign the head of each list
            
            new->size[a->v]++; // count the size of each list
            a=a->next; //move to next          
        }        
        
    }
    for(int urlIndex=0;urlIndex<(*p)->nV;urlIndex++){//TODO:
    printf("***%d\n",new->size[urlIndex]); // incidence size of each line//TODO:
    showLL(new->incidence[urlIndex]); //TODO:
    }//TODO:
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
    int urlIndex;
    for(urlIndex=0;urlIndex<N;urlIndex++){
        prs->PrArr[urlIndex]=createPrNode(urlIndex,InitPrVal); // TODO:count the outdegree
    }
    prs->nUrl=N;
    return prs;
}


/*

RankPage algorithm

*/
PrStruct Pagerank(Graph *g,PrStruct *prs,Incidence *inc){
    int N = (*g)->nV; // The total pages of the graph
    printf("%lf %lf %d",d,diffPR,maxIterations);//TODO:
    double damping_value = (1.0 - d) / N; // (1-x)/N

    
    //int numberofiter=0;
    double diff = 0;// to check the differces
    int iter;
    for(iter=0;iter<maxIterations;iter++){
    // int iter=0;
    // double diff=diffPR;  
    // while((iter<maxIterations) && (diff>=diffPR)){
    //    iter++;
        
        diff=0;
        int urlIndex;
        for(urlIndex=0;urlIndex<N;urlIndex++){ //traverse all the pages//TODO:
            //printf("--------------------------\n");
            //showLL((*g)->edges[urlIndex]);
            double rank = 0;
            //Node* a = (*g)->edges[urlIndex]; // there is no node has no outdegree
            Node* a = (*inc)->incidence[urlIndex];
            //printf("-----------$$$$$---------------\n");
            //showLL(a);
            int i;
            for(i=0;i<(*inc)->size[urlIndex];i++){
                //printf("@@%d   ",a->v);
                rank+=d*((*prs)->PrArr[a->v]->PrVal/(*prs)->PrArr[a->v]->outdegree);
                a=a->next;                    
            }
            rank+=damping_value;            
            double current_rankval =(*prs)->PrArr[urlIndex]->PrVal;
            //change+=fabs(current_rankval-rank);
            diff+=fabs(rank-current_rankval);              
            (*prs)->PrArr[urlIndex]->PrVal=rank;
                     
            
            
            //printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);
            //printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);
            //printf("^%lf \n",(*prs)->PrArr[urlIndex]->PrVal);
        }
        
        //printf("\n%.7f",diff);
        //printf("\n!!%.7f",diff);
        //printf("**%.7f",diffPR);
        //printf("\ndiff>=diffPR:%s",diff>=diffPR?"True":"False");
        if (diff < diffPR) {printf("numberofiter is %d",iter);break;}
        
        

    }

    
    for(int urlIndex=0;urlIndex<N;urlIndex++){ //TODO:
    printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);//TODO:
    printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);//TODO:
    printf("^%.7f \n",(*prs)->PrArr[urlIndex]->PrVal);//TODO:
    }//TODO:
    return *prs;

}
// Teacher's algorithm
PrStruct Pagerank1(Graph *g,PrStruct *prs,Incidence *inc){
    int N = (*g)->nV; // The total pages of the graph
    printf("%lf %lf %d",d,diffPR,maxIterations);//TODO:
    double damping_value = (1.0 - d) / N; // (1-x)/N
    double* tempArray=malloc(N*sizeof(double));//temporaily store the rank value
    
    //int numberofiter=0;
    //for(int iter=0;iter<maxIterations;iter++){
    int iter=0;
    double diff=diffPR;  
    while((iter<maxIterations) && (diff>=diffPR)){
        iter++;
        //double diff = 0;// to check the differces
        diff=0;
        int urlIndex;
        for(urlIndex=0;urlIndex<N;urlIndex++){ //traverse all the pages
            //showLL((*g)->edges[urlIndex]);
            double rank = 0;
            //Node* a = (*g)->edges[urlIndex]; // there is no node has no outdegree
            Node* a = (*inc)->incidence[urlIndex];
            int i;
            for(i=0;i<(*inc)->size[urlIndex];i++){
                //printf("@@%d   ",a->v);
                rank+=d*((*prs)->PrArr[a->v]->PrVal/(*prs)->PrArr[a->v]->outdegree);
                printf("%d %f linksfrom%d\n",i,rank,(*prs)->PrArr[a->v]->outdegree);//TODO:
                a=a->next;                    
            }
            assert(rank<1);
            rank=rank+damping_value;            
            double current_rankval =(*prs)->PrArr[urlIndex]->PrVal;
            //change+=fabs(current_rankval-rank);
            diff+=fabs(rank-current_rankval);
            printf("%d rank%f\n",urlIndex,rank);//TODO:
            tempArray[urlIndex]=rank;

            
                     
            
            //printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);
            //printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);
            //printf("^%lf \n",(*prs)->PrArr[urlIndex]->PrVal);
        }
        for(urlIndex=0;urlIndex<N;urlIndex++){ //IMPORTANT!!:  after calculate all the pagerankvalue then copy the value,otherwize when caluating,the pagerank value is not the previous one 
        (*prs)->PrArr[urlIndex]->PrVal=tempArray[urlIndex];
        }
        printf("\n%.7f",diff);//TODO:
        //printf("\n!!%.7f",diff);
        //printf("**%.7f",diffPR);
        printf("\ndiff>=diffPR:%s",diff>=diffPR?"True":"False");//TODO:
        //if (change < diffPR) {printf("numberofiter is %d",iter);break;}
        
        

    }

    printf("iteration:%d",iter);//TODO:
    for(int urlIndex=0;urlIndex<N;urlIndex++){//TODO:
    printf("\n!%d ",(*prs)->PrArr[urlIndex]->urlIndex);//TODO:
    printf("@%d ",(*prs)->PrArr[urlIndex]->outdegree);//TODO:
    printf("^%.7f \n",(*prs)->PrArr[urlIndex]->PrVal);//TODO:
    }//TODO:

    
    free(tempArray);
    return *prs;

}


/*

Create the Linked list Graph from the file

*/
Graph *createGraph(Graph *g,CollectionContext pCol,PrStruct *prs){
    assert(NULL!=pCol);
    *g = newGraph(pCol->nPages); // allocate memory for Graph
    int pIndex;
    for(pIndex=0;pIndex<pCol->nPages;pIndex++){ // traverse all the pages
        UrlContext temp=ReadUrlSection_1(pCol->urlName[pIndex]); // tempory context
        if(temp->nUrl==0) {; // if there is no page point to the page will pointer to every page
            int allindex;
            for(allindex=0;allindex<pCol->nPages;allindex++){ // traverse all the page 
                    if(allindex!=pIndex){ // it point to every page except itself                 
                        Edge tempEdge={pIndex,allindex}; //create the edge
                        insertEdge(*g,tempEdge);
                        (*prs)->PrArr[pIndex]->outdegree++;   // count the outdegree
                    }else continue;
                }        
        }
        else{
            int uIndex;
            for(uIndex=0;uIndex<temp->nUrl;uIndex++){// traverse all the links
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
    showGraph(*g);//TODO:
    return g;
}
/*

modify Insertion code from Lecture 1 Prpgram week1a to sort the pagerank

*/

void insertionSort(PrStruct * prs) {
   int n=(*prs)->nUrl; // number of the nodes
   int i;
   for (i = 1; i < n; i++) {
      double element = (*prs)->PrArr[i]->PrVal; //current Pagerank value
      int element1 = (*prs)->PrArr[i]->urlIndex; // current  UrlIndex
      int element2 = (*prs)->PrArr[i]->outdegree; // current  outdegree
      int j = i-1;
      while (j >= 0 && (*prs)->PrArr[j]->PrVal > element) {  // ... work down the ordered list
         (*prs)->PrArr[j+1]->PrVal = (*prs)->PrArr[j]->PrVal;
         (*prs)->PrArr[j+1]->outdegree = (*prs)->PrArr[j]->outdegree;
         (*prs)->PrArr[j+1]->urlIndex = (*prs)->PrArr[j]->urlIndex;               // ... moving elements up
         j--;
      }
       (*prs)->PrArr[j+1]->PrVal = element;
       (*prs)->PrArr[j+1]->outdegree=element2;
       (*prs)->PrArr[j+1]->urlIndex=element1;   // and insert in correct position
   }
}

/*

Output the txt file  with thw context:

urlXX  outdegree   PagerankValue

*/

void writePRfile(PrStruct prs,CollectionContext p,char* filename){

    FILE *fp;
    if((fp = fopen(filename,"w"))==NULL){  // open the file 
    fprintf(stderr,"Can't create output file.\n");
    exit(3);
    }
    int h;
    for (h=(prs)->nUrl-1;h!=-1;h--){
        fprintf(fp, "url%d, %d, ", (p)->urlName[(prs)->PrArr[h]->urlIndex], (prs)->PrArr[h]->outdegree);
        fprintf(fp, "%.7f\n", (prs)->PrArr[h]->PrVal);   
    }

    if(fclose(fp)!=0){  // close the file 
    fprintf(stderr,"Error in closing files\n");
}
}





int main(int argc,char * argv[]){
    
    Graph g; // the Graph 
    
    if (argv[1]!=NULL && argv[2]!=NULL && argv[3]!=NULL){ // set the new argument
    d =(double)(atof)(argv[1]); // damping factor    atof:ascii to floating point numbers
    diffPR = (double)(atof)(argv[2]); // difference in PageRank sum
    maxIterations =(int)(atoi)(argv[3]);// maximum iterations   atoi:ascii to int numbers
    }

    printf("%s %s %s\n",argv[1],argv[2],argv[3]);//TODO:
    printf("%lf %lf %d\n",d,diffPR,maxIterations); //print the argument//TODO:
    printf("%d\n",MAX); // if use include <>  could not find the include path//TODO:
    //readfile(&g,"collection.txt"); // reads data from a given collection of pages in the file 
    //g haven't been initialized,so transfer the address 
    //freeGraph(g);

    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("the name of the collection in main function\n");//TODO:
    for(int i=0;i<p->nPages;i++){//TODO:
        printf("%d ",p->urlName[i]);// check the stored integer name//TODO:
    }//TODO:
    printf("\n");//TODO:
    // ReadUrlSection_1(11);//TODO:
    printf("------SECTION2------");//TODO:
    UrlContext p2;//TODO:
    p2=ReadUrlSection_2(11);//TODO:
    printf("%d",p2->nWords);//TODO:
     for(int i=0;i<p2->nWords;i++){//TODO:
         printf("%s ",p2->words[i]);//TODO:
    }//TODO:
    printf("-----------------------------------------");//TODO:
    PrStruct prs=createPrstruct(p);
    //printf("----------------------------");
    //printf("\ntest outdegree %d\n",prs->PrArr[0]->outdegree);
    createGraph(&g,p,&prs);
    Incidence inc;
    inc=gettheincidence(&g,&prs);
    Pagerank1(&g,&prs,&inc);
    insertionSort(&prs);
    writePRfile(prs,p,"pagerankList.txt");
    printf("\n%d\n",prs->nUrl);//TODO:


    for (int h=prs->nUrl-1;h!=-1;h--){//TODO:
        printf("@@%d %d %.7f\n",p->urlName[(prs)->PrArr[h]->urlIndex],(prs)->PrArr[h]->outdegree,(prs)->PrArr[h]->PrVal);//TODO:
    }//TODO:
    //Pagerank(&g,&prs,&inc);
    return 0;
}