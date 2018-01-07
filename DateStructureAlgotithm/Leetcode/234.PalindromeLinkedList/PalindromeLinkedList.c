/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// wrong code beacuse when reverse the link the orginal list was destroyed
/*
bool isPalindrome(struct ListNode* head) {
    struct ListNode *dummy=malloc(sizeof(struct ListNode)); // create a new list;  //remember to malloc new memeory do not use  dummy =head
    struct ListNode * lastNode = NULL;
    struct ListNode * current = head;
    if (head==NULL) return 1;
    if (head->next == NULL) return 1;
    
    while(current!=NULL){
        dummy->next = current;
        current=current->next;
        dummy->next->next=lastNode;        
        lastNode = dummy->next;
    }
    dummy = dummy->next;
    while(head!=NULL&& dummy!=NULL){
        if(head->val!=dummy->val) return 0;
        head=head->next;
        dummy=dummy->next;
    }
    return 1;
    
}

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// STUPID ORGINAL METHOD  :) 
static struct ListNode * createnewNode(int val){ //create Node
    struct ListNode * new = malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

void add(struct ListNode * l,int val){
    struct ListNode* new = createnewNode(val);
    l->next = new;    
}


bool isPalindrome(struct ListNode* head) {
    struct ListNode *dummy=malloc(sizeof(struct ListNode)); // create a new list to store the reverse list;
    struct ListNode *copy=malloc(sizeof(struct ListNode)); // copy given list;
    struct ListNode * cur=head; // traverse in given list
    struct ListNode * curcopy = copy; // traverse in new list which to copy the given list
    
    while(cur!=NULL){  //copy the list
        add(curcopy,cur->val);
        cur=cur->next;
        curcopy= curcopy->next;
    }
     
    
    
    
    struct ListNode * lastNode = NULL; 
    struct ListNode * current = head; 
    if (head==NULL) return 1;
    if (head->next == NULL) return 1;
    // ATTENTION !! this method to reverse the list will destroy the original list
    while(current!=NULL){
        dummy->next = current;
        current=current->next;
        dummy->next->next=lastNode;        
        lastNode = dummy->next;
    }
    dummy = dummy->next;
    copy = copy->next;
    while(copy!=NULL&& dummy!=NULL){ // COMPARE THE TWO LIST
        if(copy->val!=dummy->val) return 0;
        copy=copy->next;
        dummy=dummy->next;
    }
    return 1;
    
}