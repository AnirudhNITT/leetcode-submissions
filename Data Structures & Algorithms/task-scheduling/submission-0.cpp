class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int,vector<int>>pq;
        vector<int>freq_arr(26,0);
        for(int i=0;i<tasks.size();i++){
            freq_arr[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq_arr[i]==0)continue;
            else{
                pq.push(freq_arr[i]);
            }
        }
        int ans=0;
        while(!(pq.empty())){
            int k=n+1;
            vector<int>temp;
            while(k>0 && !(pq.empty())){
                int val=pq.top();
                pq.pop();
                ans++;
                if(val-1>0){
                    temp.push_back(val-1);
                }
                k--;
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            if(!(pq.empty())){
                ans+=k;
            }
        }
        return ans;
    }
};
