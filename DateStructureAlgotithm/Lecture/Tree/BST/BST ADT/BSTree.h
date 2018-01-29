// Binary Search Tree ADT interface

# include <stdbool.h>

typedef int Item;  // item is just a key

typedef struct Node * Tree;

Tree newTree();  // create an empty Tree
void freeTree(Tree); // free memory associate with Tree
void showTree(Tree); // display a Tree(sideways)

bool TreeSearch(Tree,Item); // check whether an item is in a Tree
int TreeHeight(Tree);   //compute height of Tree
int TreeNumNode(Tree);  // count #nodes in tree
Tree TreeInsert(Tree,Item); //insert a new item into a Tree
Tree TreeDelete(Tree,Item); // delete an item from a tree

//internal functions made visable for testing
Tree rotateRight(Tree);
Tree rotateLeft(Tree);
Tree insertAtRoot(Tree,Item);
Tree partition(Tree,int);
Tree rebalance(Tree);