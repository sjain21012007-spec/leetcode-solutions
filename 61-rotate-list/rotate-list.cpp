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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
              return head;
        }
        ListNode* tail = head;
        int length =1;
        while(tail->next!=NULL)
        {
            tail=tail->next;
            length++;
        }
        k = k%length;
        if(k==0)
        {
            return head;
        }
        ListNode* temp = head;
        k = length-k;
        int cnt =1;
        while(cnt!=k)
        {
            temp = temp->next;
            cnt++;
        }
        tail->next = head;
        head= temp->next;
        temp->next = NULL;
        return head;
    }
};