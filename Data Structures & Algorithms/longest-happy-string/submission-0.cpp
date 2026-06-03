class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        int curr_idx=0;
        string soln="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int freq=top.first;
            int alpha=top.second;
            if(curr_idx>=2 &&(soln[curr_idx-1]==alpha && soln[curr_idx-2]==alpha)){
                if(pq.empty())return soln;
                auto next=pq.top();
                pq.pop();
                int next_freq=next.first;
                int next_alpha=next.second;
                soln.push_back(next_alpha);
                if(next_freq>1)pq.push({next_freq-1,next_alpha});
                pq.push({freq,alpha});
                curr_idx++;
            }
            else{
                soln.push_back(alpha);
                if(freq>1)pq.push({freq-1,alpha});
                curr_idx++;
            }
        }
        return soln;
    }
};