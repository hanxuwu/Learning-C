/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {  // the delete node will be assign the value of the next;
    struct ListNode * temp;
    temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp); 
       
}