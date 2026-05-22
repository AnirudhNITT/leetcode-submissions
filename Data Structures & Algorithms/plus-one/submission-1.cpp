class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr_it=digits.size()-1;
        int carry=1;
        for(int i=curr_it;i>=0;i--){
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
            if(carry==0)return digits;
        }
        if(carry==1){
            vector<int>new_ans;
            new_ans.push_back(1);
            for(int i=0;i<digits.size();i++){
                new_ans.push_back(0);
            }
            return new_ans;
        }
       
    }
};
