class Solution {
public:
    bool is_palindrome(string s,int count,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                if(count==1)return false;
                return (is_palindrome(s,1,l,r-1) || is_palindrome(s,1,l+1,r));
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        return is_palindrome(s,0,0,s.size()-1);
    }
};