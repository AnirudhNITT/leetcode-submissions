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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* soln_head=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* curr_next;
        ListNode* prev_tail=NULL;
        while(curr!=NULL){
            ListNode* check=curr;
            for(int i=0;i<k;i++){
                if(check==NULL) return soln_head==NULL ? head : soln_head;
                check=check->next;
            }
            ListNode*  curr_head=NULL;
            ListNode* curr_tail=curr;
            prev=check;
            for(int i=0;i<k;i++){
                curr_next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=curr_next;
            }
            curr_head=prev;
            if(soln_head==NULL)soln_head=curr_head;
            curr_tail->next=curr;
            if(prev_tail!=NULL){
                prev_tail->next=curr_head;
            }
            prev_tail=curr_tail;
        
        }
        return soln_head;
    }
};
