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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int size=0;
        ListNode*curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        vector<int>vec(2*size-1);
        curr=head;
        int iter=0;
        while(iter<vec.size()){
            vec[iter]=curr->val;
            iter+=2;
            curr=curr->next;
        }
        iter=2;
        while(iter<vec.size()){
            vec[iter-1]=gcd(vec[iter],vec[iter-2]);
            iter+=2;
        }
        ListNode* new_curr=head;
        ListNode* soln=new_curr;
        for(int i=1;i<vec.size();i++){
            ListNode* temp= new ListNode(vec[i]);
            new_curr->next=temp;
            new_curr=new_curr->next;
            new_curr->next = NULL;
        }
        return soln;


    }
};