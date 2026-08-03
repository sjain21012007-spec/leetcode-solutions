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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        if(head->next->next==NULL)
        {
            return head;
        }

        ListNode* temp = head;
        ListNode* head2 = head->next;
        ListNode* temp1 = head->next;
        ListNode* temp2 = temp1->next;
     
     while(temp2!=NULL && temp2->next!=NULL)
     {
        temp->next= temp2;
        temp1->next = temp2->next;
        temp= temp->next;
        temp1=temp1->next;
        temp2=temp1->next;
     }
     
     if(temp2!=NULL)
     {
        temp->next= temp2;
         temp= temp->next;
         temp1->next = NULL;   
     }
     temp->next = head2;
     return head;
}
};