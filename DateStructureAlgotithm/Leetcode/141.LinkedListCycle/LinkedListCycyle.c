/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode * fast=head;  //fast pointet
    struct ListNode * slow =head; // slow pointer
    if (head==NULL) return 0;
    //if (head->next==head) return 1;
    //if (head->next==NULL) return 0;
    while (fast->next != NULL && fast->next->next != NULL) {   // if no cycle,the pointer could reach the end 
            slow = slow->next;  
            fast = fast->next->next;  
            if (slow == fast)  
                return 1;  
        }  
        return 0;  
    }

    