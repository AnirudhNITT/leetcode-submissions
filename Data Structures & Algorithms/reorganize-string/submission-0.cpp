class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]=1;
            else mp[s[i]]++;
        }
        for(auto it :mp){
            pq.push({it.second,it.first});
        }
        string soln="";
        int curr_idx=0;
        while(!pq.empty()){
            auto top=pq.top();
            int count=top.first;
            char alpha=top.second;
            pq.pop();
            if(curr_idx!=0 && soln[curr_idx-1]==alpha){
                if(pq.empty())return "";
                else {
                    auto next=pq.top();
                    int next_count=next.first;
                    char next_char=next.second;
                    pq.pop();
                    soln.push_back(next_char);
                    if(next_count>1)pq.push({next_count-1,next_char});
                    pq.push({count,alpha});
                    curr_idx++;
                }
            }
            else{
                soln.push_back(alpha);
                if(count>1)pq.push({count-1,alpha});
                curr_idx++;
            }
        }
        return soln;
    }
};