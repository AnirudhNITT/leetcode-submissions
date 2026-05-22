class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size_s1=s1.size();
        int l=0;
        int r=size_s1-1;
        multiset<char>set1;
        multiset<char>set2;
        for(int i=0;i<size_s1;i++){
            set1.insert(s1[i]);
            set2.insert(s2[i]);
        }
        while(r<s2.size()){
            if(set1==set2){
                return true;
            }
            set2.erase(set2.find(s2[l]));
            l++;
            r++;
            set2.insert(s2[r]);

        }
        return false;
        
        
    }
};
