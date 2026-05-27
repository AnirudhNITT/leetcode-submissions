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

    priority_queue<
        pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>
    > pq;

    ListNode* delete_head(ListNode *head){
        if(head==NULL)return head;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        vector<bool> done(size,false);
        int count=0;
        while(count<size){
            for(int i=0;i<lists.size();i++){
                auto curr_head=lists[i];
                if(curr_head==NULL){
                    if(!done[i]){
                        done[i]=true;
                        count++;
                    }
                }
                else{
                    pq.push({curr_head->val,curr_head});
                    lists[i]=delete_head(curr_head);
                }
            }
        }
        ListNode* ans_head=NULL;
        ListNode* prev=NULL;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ListNode* node=top.second;
            if(ans_head==NULL){
                ans_head=node;
                prev=ans_head;
                prev->next=NULL;
            }
            else{
                prev->next=node;
                prev=prev->next;
                prev->next=NULL;
            }
        }
        return ans_head;
    }
};