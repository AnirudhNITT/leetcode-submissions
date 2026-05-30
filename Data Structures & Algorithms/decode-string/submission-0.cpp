class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        stack<int>digit;
        bool flag=false;
        string curr_digit="";
        for(char it :s){
            if(it==']'){
                string curr="";
                while(st.top()!='['){
                    curr.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int n=digit.top();
                digit.pop();
                reverse(curr.begin(),curr.end());
                for(int i=0;i<n;i++){
                    for(char x :curr){
                        st.push(x);
                    }
                }
            }
            else if(isdigit(it)){
                curr_digit.push_back(it);
            }
            else if(it==']')continue;
            else {
                st.push(it);
                if(curr_digit.size()!=0){
                    digit.push(stoi(curr_digit));
                    curr_digit="";
                   
                }
            }

        }
        string soln;
        while(!st.empty()){
            soln.push_back(st.top());
            st.pop();
        }
        reverse(soln.begin(),soln.end());
        return soln;

    }
};