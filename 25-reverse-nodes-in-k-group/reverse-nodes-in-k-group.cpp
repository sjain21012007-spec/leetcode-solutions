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
     ListNode* reverseList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
            return head;
        }
          ListNode* temp1 = head;
          ListNode* temp2 = head->next;
          temp1->next = nullptr;
          while(temp2->next!=NULL)
          {
              ListNode* temp3 = temp2->next;
              temp2->next = temp1;
              temp1= temp2;
              temp2 = temp3;
          }   
          temp2->next = temp1;
          return temp2;   
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL && head->next==NULL)
        {
            return head;
        }
        int cnt =1;
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* temp3 = temp;
        while(temp2!=NULL)
        {
            if(cnt==k)
            {
                if(temp==head)
                {
                    temp= temp2->next;
                    temp2->next = NULL;
                    head = reverseList(temp3);
                    temp3->next = temp;
                    temp2 = temp;
                    cnt =1;
                }
                else{
                    temp= temp2->next;
                    temp2->next = NULL;
                    temp2= temp3->next;
                    temp3->next = reverseList(temp2);
                    temp2->next = temp;
                    temp3 =temp2;
                    temp2= temp; 
                    cnt =1;
                }
            }
           if(temp2!=NULL && temp2->next!=NULL) temp2= temp2->next;
           else break;
            cnt++;
        }
         return head;
    }
};