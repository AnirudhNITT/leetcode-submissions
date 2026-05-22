class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        while(true){
            if(n==1)return true;
            else{
                if(s.find(n)!=s.end())return false;
                s.insert(n);
                int res=0;
                while(n>0){
                    res+=(pow(n%10,2));
                    n=n/10;
                }
                n=res;
                res=0;
            }
        }
        return false;
    }
};
