class Solution {
public:

    string encode(vector<string>& strs) {
        string encode="";
        for(int i=0;i<strs.size();i++){
            encode+=strs[i]+'.';
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string>decoder;
        string decode="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='.')decode+=s[i];
            else{
                decoder.push_back(decode);
                decode="";
            }
        }
        return decoder ;
    }
};
