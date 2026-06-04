class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        q.push(0);
        int furthest=0;
        while(!q.empty()){
            int front=q.front();
            if(front==n-1)return true;
            q.pop();
            int start=max(front+minJump,furthest);
            int end=min(front+maxJump,n-1);
            for(int i=start;i<=end;i++){
                if(s[i]=='0')q.push(i);

            }
            furthest=end+1;


        }
        return false;
    }
};