/*
 Inverted Index ADT (partial) implementation, written by Ashesh Mahidadia Jan 2018.
 You may need to modify the following implementation and test it properly before using 
 in your program.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "InvertedIdx.h"



// make a new node containing data
Tree newNode(Item it) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   strcpy(new->data, it);  // replace,   data(new) = it;
   left(new) = right(new) = NULL;
   //new->treeurl =newTree();
   new->list = newDLListStr();
   return new;
}

// create a new empty Tree
Tree newTree() {
  Tree t = malloc(sizeof(Node));
  assert(t != NULL);
  left(t) = right(t) = NULL;
  return t;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   
   if (t != NULL) {
      
      showTreeR(right(t), depth+1);
      int i;
      //for (i = 0; i < depth; i++)
	// putchar('\t');// TAB character
      //if(depth!=0) {printf("%s\n", data(t));showTree(t->treeurl);};
      if(depth!=0) {printf("%s\n", data(t));showDLListStr(t->list);};
      
      //printf("%s\n", data(t));
      showTreeR(left(t), depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}

// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
   if (t == NULL)
      return false;

   else if (strcmp(it, data(t)) < 0)   //replace, else if (it < data(t))
      return TreeSearch(left(t), it);
   
   else if (strcmp(it, data(t)) > 0)  //replace, else if (it > data(t))
      return TreeSearch(right(t), it);

   else                                 // it == data(t)
      return true;
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, Item it,Tree *located) {
   
   if (t == NULL){
      t = newNode(it);
      printf("!%s \n",(t)->data); // the word not in the tree,create a new one
      *located=t;
      //return t;
   }
   else if (strcmp(it, data(t)) == 0){ // find the words
      printf("!%s \n",(t)->data);
      *located=t;
      //return t;
   }

   else if (strcmp(it, data(t)) < 0)   //replace, else if (it < data(t))
      left(t) = TreeInsert(left(t), it, located);

   else if (strcmp(it, data(t)) > 0)  //replace, else if (it > data(t))
      right(t) = TreeInsert(right(t), it,located);   
   
   return t;
}

