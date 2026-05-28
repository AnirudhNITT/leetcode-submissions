class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str="";
        int curr_iter=0;
        bool flag=true;
        if(strs.size()==1)return strs[0];
        while(flag){
            int count=0;
            for(int i=1;i<strs.size();i++){
                if(curr_iter>=strs[i].size()){
                    flag=false;
                    break;
                }
                if(strs[i][curr_iter]==strs[i-1][curr_iter])count++;
            }
            if(count==strs.size()-1){
                str.push_back(strs[0][curr_iter]);
                curr_iter++;
            }
            else{
                flag=false;
            }
            
        }
        return str;
    }
};