class Solution {
public:
    bool is_divisor(string small,string big){
        int small_size=small.size();
        int big_size=big.size();
        if(big_size%small_size!=0)return false;
        int num_iter=big_size/small_size;
        int i=0;
        int curr_iter=0;
        while(curr_iter<num_iter){
            if(big.substr(i,small_size)!=small)return false;
            i+=small_size;
            curr_iter++;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()<str2.size())return gcdOfStrings(str2,str1);
        string curr_str="";
        string ans="";
        for(int i=0;i<str2.size();i++){
            curr_str.push_back(str2[i]);
            if(is_divisor(curr_str,str1) && is_divisor(curr_str,str2))
                ans=curr_str;
        }
        return ans;
    }
};