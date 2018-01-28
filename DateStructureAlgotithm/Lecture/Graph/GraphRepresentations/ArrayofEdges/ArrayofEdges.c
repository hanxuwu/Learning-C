/*

Array of Edge Representation  ADT

*/

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "graph.h"

typedef struct GraphRep{
    Edge *edges;// array of edges
    int nV; // vertices (numberd 0..nV-1)
    int nE; // edges
    int n; //sizeof edge array
}GraphRep;

Graph newGraph(int V){ // number of vertices
    assert(V>=0);
    Graph g = malloc(sizeof(GraphRep));
    assert(NULL!=g);

    g->nV = V;
    g->nE = 0;
    // allocate enough memory for edges
    int Enough = V*(V-1)/2;
    g->n = Enough;
    g->edges = malloc(g->n*sizeof(Edge));
    assert(NULL!=g->edges);
    return g;
}

// check if two edges are equal (undirected)
bool eq(Edge e1,Edge e2){
    return ((e1.v==e2.v)&&(e1.w==e2.w))||((e1.v ==e2.w && e1.w==e2.v));
}

void insertEdge(Graph g,Edge e){
    //ensure that g exists and array of edges isn't full
    assert(g!=NULL&&g->nE<g->n);
    int i=0;
    while(i<g->nE&&!eq(e,g->edges[i])) i++;
    if (i==g->nE) g->edges[g->nE++] = e;  // edge e not found  after insert count the edges 
}

void removeEdge(Graph g,Edge e){
    assert(g!=NULL);
    int i =0;
    while(i<g->nE && !eq(e,g->edges[i])) i++;
    if(i<g->nE) g->edges[i] = g->edges[--g->nE]; // if find the edge, make the last one instead of it
}

bool adjacent(Graph g,Vertex x,Vertex y){
    assert(NULL!=g);
    Edge e;
    e.v = x;
    e.w = y;
    int i=0;
    while (i<g->nE){
        if (eq(e,g->edges[i])) return true;
        i++;
    }
    return false;
}

void showGraph(Graph g) {
    assert(g != NULL);

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    int i;
    for (i = 0; i < g->nE; i++)
       printf("Edge %d - %d\n", g->edges[i].v, g->edges[i].w);
}

void freeGraph(Graph g) {
   assert(g != NULL);

   free(g->edges);
   free(g);
}

