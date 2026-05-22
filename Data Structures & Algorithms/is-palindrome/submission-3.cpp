class Solution {
public:
    bool isPalindrome(string s) {

        auto start=s.begin();
        auto end=s.end()-1;
        while (start<end){
            while(start<end && !isalnum(*start))start++;
            while(start<end && !isalnum(*end))end--;
            if (tolower(*start)!=tolower(*end)){
                return false;
            }
            start++;
            end--;
        }
        return true;}
};

