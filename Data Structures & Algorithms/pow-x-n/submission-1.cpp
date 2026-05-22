class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n>0){
        if (n==1)return x;
        else{
            return x*myPow(x,n-1);
        }
        }
        else{
            if(n==0)return x;
            return myPow(x,n+1)/x;
        }
    }
};
