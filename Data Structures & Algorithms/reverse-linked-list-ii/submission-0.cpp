class Solution {
public:
    ListNode* reverseBetween(ListNode* head,int left,int right) {
        if(head==NULL || left==right)return head;
        ListNode* start;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int start_count=1;
        while(start_count<left){
            prev=curr;
            curr=curr->next;
            start_count++;
        }
        ListNode* before_start=prev;
        start=curr;
        prev=NULL;
        while(start_count<=right){
            ListNode* curr_next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=curr_next;
            start_count++;
        }
        start->next=curr;
        if(before_start!=NULL){
            before_start->next=prev;
            return head;
        }
        return prev;
    }
};