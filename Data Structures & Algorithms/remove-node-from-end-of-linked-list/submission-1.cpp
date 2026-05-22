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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        if(count==1){
            free(head);
            return NULL;
        }
        else if(n==count){
            ListNode* temp=head->next;
            free(head);
            head=temp;
        }
        else if(n==1){
            ListNode* current=head;
            while(current->next->next!=NULL){
                current=current->next;
            }
            ListNode*nextnode=current->next;
            current->next=NULL;
            free(nextnode);
        }
        else{
            ListNode*now=head;
            int c=0;
            while(c<(count-n-1)){
                now=now->next;
                c++;
            }
            ListNode*unfortunate=now->next;
            now->next=unfortunate->next;
            delete unfortunate;

            
        }
        return head;
    }
};
