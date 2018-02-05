
#include <stdio.h>
#include <stdbool.h>

typedef int Vertex; 
#define MAX_NODE 10
#define VERY_HIGH_VALUE 99999

void showPath(int v,int pred[]){
    if(pred[v]==-1){
        printf("%d",v);
    }else{
        showPath(pred[v],pred);
        printf("-%d",v);
    }
}

void dijkstraSSSP(Graph g,int nV,Vertex source){
    int dist[MAX_NODE];
    int pred[MAX_NODE];
    bool vSet[MAX_NODE]; // vSet[v] = true <=> v has not been processed
    int s,t;

    PQueueInit();
    for(s=0;s<nV;s++){
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }

    dist[source] = 0;
    while(!PQueueIsEmpty()){
        s = leavePQueue(dist);
        vSet[s]=false;
        for(t=0;t<nV;t++){
            if(vSet[t]){
                int weight = adjacent(g,s,t);
                if(weight>0 && dist[s]+weight<dist[t]){ //relax along (s,t,weight)
                    dist[t] = dist[s]+weight;
                    pred[t] = s;
                }
            }
        }
    }

    for(s=0;s<nV;s++){
        printf("%d: ",s);
        if(dist[s]<VERY_HIGH_VALUE){
            printf("distance = %d, shortest path:",dist[s]);
            showPath(s,pred);
            putchar('\n');
        }else{
            printf("no path\n");
        }
    }
}