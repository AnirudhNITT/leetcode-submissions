class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()!=0){
            if(pq.size()==1){
                return pq.top();
            }
            else{
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                if(x==y){
                    pq.pop();
                }
                else{
                    pq.pop();
                    pq.push(abs(x-y));
                }
            }
        }
        if(pq.size()==0)return 0;
    }
};
