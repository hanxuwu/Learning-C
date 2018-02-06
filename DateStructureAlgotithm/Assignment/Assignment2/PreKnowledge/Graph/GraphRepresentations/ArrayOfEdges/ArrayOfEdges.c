# include <stdio.h>
# include <assert.h>
# include <stdlib.h>

/*

gcc -o ArrayOfEdges ArrayOfEdges.c

*/


typedef int Vertice;

typedef struct Edge{
    Vertice v;
    Vertice w;
}Edge;

typedef struct ArrayGraphRep{
    int nVertices;
    int nEdges;
    Edge *Edges;
    int n;    // sizeof the edge array;
}ArrayGraphRep;

typedef struct ArrayGraphRep * ArrayGraph;

static Edge createEdge(Vertice a,Vertice b){
    Edge newEdge;
    newEdge.v = a;
    newEdge.w = b;
    return newEdge;
}

ArrayGraph NewArrayGraph(){
    ArrayGraph newGraph;
    newGraph = malloc(sizeof(ArrayGraphRep));
    assert(newGraph!=NULL);
    newGraph->nVertices = 0;
    newGraph->nEdges = 0;
    printf("Please input the number of vertices\n");
    scanf("%d",&newGraph->nVertices);
    int enough = newGraph->nVertices *(newGraph->nVertices-1)/2;
    newGraph ->n = enough;
    newGraph ->Edges = malloc(enough* sizeof(Edge));
    return newGraph;

}


// if the edge is same
int eq(Edge e1,Edge e2){
    return ((e1.v==e2.v && e1.w == e2.w)||(e1.v ==e2.w && e1.w ==e2.v));
}


int InsertEdge(ArrayGraph g,Edge e){ // success return 1,fail return 0;
    assert(NULL!=g && g->nEdges <g->n);
    int i =0;
    while(i<g->nEdges && !eq(e,g->Edges[i])) i++;
    printf("@@@@@%d\n",i);
    if(i == g->nEdges)
        g->Edges[g->nEdges++] = e;

}

void displayEdge(ArrayGraph g){
    assert(NULL!=g);
    for (int i=0;i<g->nEdges;i++){
        printf("%d %d\n",g->Edges[i].v,g->Edges[i].w);

    }
}

int adjacent(ArrayGraph g,Vertice v,Vertice w){
    Edge a;
    a.v = v;
    a.w = w;
    int i = 0;
    while(i<g->nEdges){
        if(eq(a,g->Edges[i]))
            return 1;
        i++;
    }
    return 0;
}






int main(int argc,char * argv[]){
    ArrayGraph Graph1 = NewArrayGraph();
    printf("number of vertices %d\n",Graph1->nVertices);
    printf("size of array %d\n",Graph1->n);
    Edge new = createEdge(3,5);
    InsertEdge(Graph1,new);
    displayEdge(Graph1);
    //printf("%d   %d\n",Graph1->Edge[0].v,Graph1->Edges[0].w);
    //printf("%d   %d\n",Graph1->Edge[1].v,Graph1->Edges[1].w);
    new = createEdge(4,6);
    InsertEdge(Graph1,new);
    displayEdge(Graph1);
    //printf("%d   %d\n",Graph1->Edge[1].v,Graph1->Edges[1].w);
    new = createEdge(8,9);
    InsertEdge(Graph1,new);
    displayEdge(Graph1);
    printf("%d",adjacent(Graph1,8,9));
    return 0;

}


/**
 * 
 * 
Please input the number of vertices
5
number of vertices 5
size of array 10
@@@@@0
3 5
@@@@@1
3 5
4 6
@@@@@2
3 5
4 6
8 9
1%

 * 
 * 
 * 
 **/