class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()){
        return false;
        
       }
       multiset<char>ms1;
       multiset<char>ms2;
       for (char x:s){
            ms1.insert(x);
       }
       for (char z:t){
            ms2.insert(z);
       }
       for(char y:t){
            if(ms1.count(y)!=ms2.count(y)){
                return false;
                break;

            }
       }
       return true;

    }
};
