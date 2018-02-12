# include <stdio.h>
# include <stdlib.h>
# include "graph.h"

# define MAX 1000
int visit[MAX];


bool dfsPathCheck(Graph g,int nV,int v,int dest){
    Vertex w;
    for(w=0;w<nV;w++){
        if(adjacent(g,w,v)&&visit[w]==-1){
            visit[w]=v;
            if(w==dest) return true;
            else if(dfsPathCheck(g,nV,w,dest)) return true;
        }
    }
    return false;
}

bool findPathDFS(Graph g,int nV,int src,int dest){
    Vertex v;
    for(v=0;v<nV;v++) visit[v]=-1;
        visit[src]=src;
    
    return dfsPathCheck(g,nV,src,dest);
}

int main(void){
    int V=6;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0; e.w = 1; insertEdge(g, e);
    e.v = 0; e.w = 4; insertEdge(g, e);
    e.v = 0; e.w = 5; insertEdge(g, e);
    e.v = 5; e.w = 4; insertEdge(g, e);
    e.v = 4; e.w = 2; insertEdge(g, e);
    e.v = 4; e.w = 3; insertEdge(g, e);
    e.v = 5; e.w = 3; insertEdge(g, e);
    e.v = 1; e.w = 2; insertEdge(g, e);
    e.v = 3; e.w = 2; insertEdge(g, e);
    showGraph(g);

    int src = 0,dest =5;
    if(findPathDFS(g,V,src,dest)){
        Vertex v =dest;
        while(v!=src){
            printf("%d - ",v);
            v = visited[v];
        }
        printf("%d\n",src);
    }
    return 0;

}