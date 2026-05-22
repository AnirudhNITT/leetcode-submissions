class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string &tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                if (st.size() < 2) return 0; // or handle error as required

                int right = st.top(); st.pop();
                int left  = st.top(); st.pop();

                int res;
                if (tok == "+") res = left + right;
                else if (tok == "-") res = left - right;
                else if (tok == "*") res = left * right;
                else if (tok == "/") res = left / right; 
                st.push(res);
            } else {
                st.push(stoi(tok));
            }
        }

        return st.empty() ? 0 : st.top();
    }
};
