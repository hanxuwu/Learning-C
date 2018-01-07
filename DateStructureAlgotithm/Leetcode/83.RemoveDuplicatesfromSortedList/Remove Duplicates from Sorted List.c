/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * current = head;
    struct ListNode * lastNode = head;
    if (head==NULL||head->next == NULL) return head; // empty and there is only one element in list;
    int temp=head->val;
    while(current!=NULL){        
        
        if(current->val!=temp) { // search for the next different node
            lastNode->next = current;
            temp = current->val;
            lastNode = current;
                               }        
        current=current->next;
    }
    lastNode->next = NULL; // remember to end the list
    return head;
    

    
}