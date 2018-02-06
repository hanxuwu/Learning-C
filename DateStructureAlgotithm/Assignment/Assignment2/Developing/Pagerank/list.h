// Linked list interface ... COMP9024 17s2
#include <stdbool.h>

typedef struct Node {
   int v;
   struct Node *next; 
} Node;

typedef struct Node *List;

List insertLL(List, int);
List deleteLL(List, int);
bool inLL(List, int);
void freeLL(List);
void showLL(List);