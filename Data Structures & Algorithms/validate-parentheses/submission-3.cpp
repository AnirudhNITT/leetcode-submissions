class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else { 
                if (st.empty()) return false; 
                char a = st.top();
                
                if ((a == '(' && x == ')') ||
                    (a == '{' && x == '}') ||
                    (a == '[' && x == ']')) {
                    st.pop();
                } else {
                    return false; 
                }
            }
        }
        return st.empty();
    }
};

