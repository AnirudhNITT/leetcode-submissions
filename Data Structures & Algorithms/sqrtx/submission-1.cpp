class Solution {
public:
    int mySqrt(long long x) {
        long long l=1;
        long long r=x;
        long long mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid*mid>x)r=mid-1;
            else if(mid*mid<x)l=mid+1;
            else return mid;
        }
        return r;
    }
};