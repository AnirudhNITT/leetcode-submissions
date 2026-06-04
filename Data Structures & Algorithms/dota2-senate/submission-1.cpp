class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q_rad;
        queue<int>q_dir;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R')q_rad.push(i);
            else q_dir.push(i);
        }
        while(!q_rad.empty()&&!q_dir.empty()){
            int f1=q_rad.front();
            q_rad.pop();
            int f2=q_dir.front();
            q_dir.pop();
            if(f1>f2){
                q_dir.push(f2+n);
            }
            else{
                q_rad.push(f1+n);
            }
        }
        if(q_rad.empty())return "Dire";
        return "Radiant";
    }
};