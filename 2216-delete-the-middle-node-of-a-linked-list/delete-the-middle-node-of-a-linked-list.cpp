/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         
         if(head==NULL || head->next==NULL)
         {
            return NULL;
         }
        
           ListNode* t1 = head->next->next;
           ListNode* t2 = head;
        while(t1!=NULL && t1->next!=NULL)
        {    
                t1 = t1->next->next;
                t2 = t2->next;
        }      
            ListNode* middle = t2->next;
            t2->next = t2->next->next;
           delete middle;

    
        return head;
    }
};