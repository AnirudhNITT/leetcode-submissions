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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&& fast->next){
            slow=slow->next;
            fast=fast->next->next;

        }
        fast=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        ListNode* succ=NULL;
        while(fast!=NULL){
           succ = fast->next;
            fast->next = prev;
            prev = fast;
            fast = succ;


        }
        ListNode* head_rev=prev;
        ListNode* curr2=head_rev;
        ListNode* curr1=head;
        ListNode* temp1=NULL;
        ListNode* temp2=NULL;
       while(curr2){
            temp1=curr1->next;
            temp2=curr2->next;
            curr1->next=curr2;
            curr2->next=temp1;
            curr1=temp1;
            curr2=temp2;


        }



    }
};
