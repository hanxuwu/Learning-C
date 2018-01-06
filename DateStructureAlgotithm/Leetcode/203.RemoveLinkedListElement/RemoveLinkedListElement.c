/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode * dummy = malloc(sizeof(struct ListNode)); //create a new linked list, then add the none val value;
    struct ListNode * lastNode = dummy;
    while(head!=NULL){
        if (head->val!=val){
            lastNode->next = head;
            head=head->next;
            lastNode = lastNode->next;
        }else{
            
            head = head->next;
        }
        
    }
    lastNode->next = NULL; // remember to mark the end!
    return dummy->next;
    
    
}