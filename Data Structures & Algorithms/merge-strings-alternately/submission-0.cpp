class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1=0;
        int p2=0;
        string soln;
        while(p1<word1.size() && p2<word2.size()){
            soln.push_back(word1[p1]);
            soln.push_back(word2[p2]);
            p1++;
            p2++;
        }
        while(p1<word1.size()){
            soln.push_back(word1[p1]);
            p1++;
        }
        while(p2<word2.size()){
            soln.push_back(word2[p2]);
            p2++;
        }
        return soln;
    }
};