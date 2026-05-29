class Solution {
public:
    int calPoints(vector<string>& op) {
        int curr_sum=0;
        int curr_top,next_top,prev_top;
        stack<int>st;
        for(int i=0;i<op.size();i++){
            if(op[i]=="+"){
                curr_top=st.top();
                st.pop();
                prev_top=st.top();
                next_top=curr_top+prev_top;
                st.push(curr_top);
                st.push(next_top);
                curr_sum+=next_top;
            }
            else if(op[i]=="D"){
                curr_top=st.top();
                st.push(curr_top*2);
                curr_sum+=curr_top*2;
            }
            else if(op[i]=="C"){
                curr_top=st.top();
                st.pop();
                curr_sum-=curr_top;
            }
            else{
                curr_sum+=(stoi(op[i]));
                st.push(stoi(op[i]));
            }
        }
        return curr_sum;
    }
};