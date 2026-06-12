class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>afford;
        for(int i=0;i<profits.size();i++){
            afford.push_back({capital[i],profits[i]});
        }
        sort(afford.begin(),afford.end());
        priority_queue<int>pq;
        int curr=0;
        int iter=0;
        while(curr<k){
            while(iter<afford.size() && w>=afford[iter].first ){
                pq.push(afford[iter].second);
                iter++;
            }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
            curr++;
        }
    return w;
        
    }
};