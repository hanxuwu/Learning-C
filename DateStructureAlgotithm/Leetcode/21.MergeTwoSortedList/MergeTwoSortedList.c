/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * dummy = malloc(sizeof(struct ListNode)); // create a new list for returning
    struct ListNode * lastNode = dummy; // last Node
    while(l1!=NULL && l2!=NULL){   // if a list reach end,then add another  list to the end 
        if(l1->val<=l2->val){
            lastNode ->next = l1;
            l1 = l1->next;
        }else{
            lastNode ->next =l2;
            l2 = l2->next;
        }
        lastNode = lastNode->next;
    }

    struct ListNode * l = NULL;
    l = (l1==NULL?l2:l1);  // which is the rest list
    lastNode ->next = l;
    return dummy->next;
    
}

