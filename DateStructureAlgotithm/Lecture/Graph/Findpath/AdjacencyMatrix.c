/*

Adjacency Matrix

*/
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "graph.h"

typedef struct GraphRep{
    int ** edges; // adjacency matrix
    int nV; // # vertices
    int nE; // # edges
}GraphRep;

Graph newGraph(int V){
    assert(V>=0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(NULL!=g);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(NULL!=g->edges);
    // allocate memory for each column and initialise with 0
    for(i=0;i<V;i++){
        g->edges[i] = calloc(V,sizeof(int));
        assert(NULL!=g->edges[i]);
    }
    return g;
}

// check if vertex is valid in a graph  
bool validV(Graph g,Vertex v){
    return (g!=NULL && v>=0 && v< g->nV);
}

void insertEdge(Graph g,Edge e){
    assert(g!=NULL && validV(g,e.v)&&validV(g,e.w));
    if(!g->edges[e.v][e.w]){ // edge not in graph
        g->edges[e.v][e.w]=1;
        g->edges[e.w][e.v]=1;
        g->nE++;
    }
}

void removeEdge(Graph g,Edge e){
    assert(g!=NULL && validV(g,e.v)&&validV(g,e.w));
    if(g->edges[e.v][e.w]){ // edge not in graph
        g->edges[e.v][e.w]=0;
        g->edges[e.w][e.v]=0;
        g->nE--;
    }
}

bool adjacent(Graph g,Vertex x,Vertex y){
    assert(NULL!=g && validV(g,x)&&validV(g,y));
    return (g->edges[x][y]!=0);
}


void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
       for (j = i+1; j < g->nV; j++)
	  if (g->edges[i][j])
	      printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
   assert(g != NULL);

   int i;
   for (i = 0; i < g->nV; i++)
      free(g->edges[i]);
   free(g->edges);
   free(g);
}