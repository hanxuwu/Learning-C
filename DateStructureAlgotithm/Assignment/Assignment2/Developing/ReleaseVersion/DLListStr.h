// DLListStr.h - Interface to doubly-linked list ADT
// Written by John Shepherd, March 2013
// Last modified, Ashesh Mahidadia, Jan 2017 

#ifndef DLListStr_H
#define DLListStr_H

#include <stdio.h>
#include "DLListStr.h"

// External view of DLListStr
// Implementation given in DLListStr.c
// Implements a DLListStr of string 


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

typedef struct DLListRep *DLListStr;




// create a new empty DLListStr
DLListStr newDLListStr();



int add(DLListStr, char *);

void reset(DLListStr);
// free up all space associated with list
void freeDLListStr(DLListStr);

int insertSetOrd(DLListStr, char *);
// display items from a DLListStr, comma separated
void showDLListStr(DLListStr);



#endif
