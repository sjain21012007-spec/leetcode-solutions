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
        
           ListNode* t1 = head;
           ListNode* t2 = head;
           ListNode* t3 = head;
        while(t1!=NULL && t1->next!=NULL)
        {    
                t1 = t1->next->next;
                t3=t2;
                t2 = t2->next;

        }      

        t3->next = t2->next;
        delete(t2);
        return head;
    }
};