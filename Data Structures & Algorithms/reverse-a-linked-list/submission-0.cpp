class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* succ=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL){
            succ=curr->next;
            curr->next=prev;
            prev=curr;
            curr=succ;               
        }
        return prev;
    }
};
