# include <stdio.h>
# include <assert.h>

typedef int Vertex;

#define MAX_NODES 1000
typedef struct{
    Vertex item[MAX_NODES]; // array of vertices currently in queue
    int length;   // # values currentlt stored in item[] array
}PQueueT;

PQueueT PQueue;

void PQueueInit(){
    PQueue.length = 0;
}

// insert vertex v into priority queue PQueue
// no effect if v is already in the queue
void joinPQueue(Vertex v){
    assert(PQueue.length<MAX_NODES);
    int i=0;
    while(i<PQueue.length && PQueue.item[i]!=v) // check if v already in queue
        i++;
    if (i==PQueue.length){ //v not found --> add it at the end
        PQueue.item[PQueue.length] = v;
        PQueue.length++;
    }
}


//remove the highest priority vertex from PQueue
//remember:highest priority = lowest value priority[v]
//returns the removed vertex

#define VERY_HIGH_VALUE 9999999

Vertex leavePQueue(int priority[]){
    assert(PQueue.length>0);
    int i,bestVertex,bestIndex,bestWeight = VERY_HIGH_VALUE;
    for(i=0;i<PQueue.length;i++){
        if(priority[PQueue.item[i]]<bestWeight){
            bestIndex = i;
            bestWeight = priority[PQueue.item[i]];
            bestVertex = PQueue.item[i];
        }
    }
    PQueue.length--;
    PQueue.item[bestIndex] = PQueue.item[PQueue.length]; //replace dequed node by last element in array
    return bestVertex;
}

