/*
 Implementation of doubly-linked list ADT for string values.
 Written by Ashesh Mahidadia Jan 2018, based on code writted by John Shepherd 2015.
 You may need to modify the following implementation and test it properly before using 
 in your program.
*/


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "DLListStr.h"

// data structures representing DLListStr

typedef struct DLListNode {
	char   value[100];  // value of this list item (string)
	struct DLListNode *prev;
	               // pointer previous node in list
	struct DLListNode *next;
	               // pointer to next node in list
} DLListNode;

typedef struct DLListRep {
	int  nitems;      // count of items in list
	DLListNode *first; // first node in list
	DLListNode *curr;  // current node in list
	DLListNode *last;  // last node in list
} DLListRep;


// Create a static new Node
static DLListNode * newDLListNode(){
    DLListNode * new;
    new = malloc(sizeof(DLListNode)); // malloc a new Node
    assert(NULL!=new);
    new->prev = NULL;
    new->next = NULL;
    return new;
}

//Creates a new list iterator that can store integer values
//  |first|<---->|cursor|<----->|last|
DLListStr newDLListStr(){
    DLListStr new;
    new = malloc(sizeof(DLListRep));
    assert(NULL!=new);
    DLListNode * first = newDLListNode();// create the static first Node
    //assert(NULL!=first);
    DLListNode * last = newDLListNode(); // create the static last Node
    //assert(NULL!=last);
    DLListNode * curr = newDLListNode();
    //assert(NULL!=cursor);
    new->nitems=0; // number of elements in the list
    new->first = first;
    new->last = last;
    new->curr = curr;

    first->next=curr;  //  |first|<---->|cursor|<----->|last|
    curr->prev = first;
    curr->next =last;
    last->prev = curr;

    return new;
}

//Inserts the specified value v into the list iterator it.
int add(DLListStr it, char *val){
    it->nitems++;

    if (it==NULL) return 0; // no exist linked list return 0
    DLListNode * new;
    new=newDLListNode();
    assert(NULL!=new);
    strcpy(new->value, val);

    //new->next = it->cursor->next; // make the added one after the cursor
    //it->cursor->next->prev = new;
    //new->prev = it->cursor;
    //it->cursor->next = new;

    it->curr->prev->next=new;
    new->prev = it->curr->prev;// |first|<--->|cursor|<--->|last|
    new->next=it->curr;
    it->curr->prev = new; // |first|<--->|newNode|<--->|cursor|<--->|last|
    return 1;  // add successfully  return 1
}

//Resets it to the start of the list.
void reset(DLListStr it){
    assert(NULL!=it);
    it->curr->next->prev = it->curr->prev; // link cursor's prev and next element
    it->curr->prev->next = it->curr->next;

    it->curr->next = it->first->next; //  make the cursor after the first sentinel
    it->first->next->prev = it->curr;
    it->curr->prev = it->first;
    it->first->next = it->curr;

}

/* 
   pre-reqisite: L is ordered (increasing) with no duplicates
   post-condition: val is inserted in L, L is ordered (increasing) with no duplicates
*/
int insertSetOrd(DLListStr it, char *val){
    it->nitems++;

    if (it==NULL) return 0; // no exist linked list return 0
    DLListNode * new;
    new=newDLListNode();
    assert(NULL!=new);
    strcpy(new->value, val);

    it->curr->prev->next=new;
    new->prev = it->curr->prev;// |first|<--->|cursor|<--->|last|
    new->next=it->curr;
    it->curr->prev = new; // |first|<--->|newNode|<--->|cursor|<--->|last|
    return 1;  // add successfully  return 1


}

//Returns pointer to the next value in it that matches the given value v and advances the cursor position past the value returned.
int findNext(DLListStr it, char *val){
    reset(it);
	assert(NULL!=it);
    DLListNode * cur;
    cur=it->curr->next;
    while(cur!=it->last){
        if( strcmp(val, cur->value) <= 0){
            it->curr->prev->next=it->curr->next; //link two nodes adjacent to the cursor
            it->curr->next->prev = it->curr->prev;

            cur->next->prev = it->curr;//link cursor next to the found node
            it->curr->next = cur->next;

            it->curr->prev = cur;
            cur->next = it->curr;
            
			return 1;
        }
        cur=cur->next; // keep searching
		
    }
	
  add(it,val);
  return 0;
}

// additional function to show the link list
void showDLListStr(DLListStr it){
    assert(NULL!=it);
    DLListNode * curr;
    curr = it->first->next;
    while(curr!=it->last){
        if(curr == it->curr){
            printf(" ^,");
        }else{
            printf(" %s,",curr->value);
        }
        curr = curr->next;
    }
    printf("\n");

}