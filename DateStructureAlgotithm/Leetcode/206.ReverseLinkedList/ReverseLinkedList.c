/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// like this code ! wrote is by good luck!
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * new = malloc(sizeof(struct ListNode));
    struct ListNode * lastnode = NULL;
    while(head!=NULL){
        new->next = head;
        head = head->next;
        new->next->next = lastnode; // just make the end is NULL!  
        lastnode = new->next;       
       
    }
    return new->next;
    
}