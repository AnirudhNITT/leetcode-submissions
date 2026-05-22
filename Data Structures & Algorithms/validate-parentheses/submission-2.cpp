class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else { // x is a closing bracket
                if (st.empty()) return false; // no opening to match
                char a = st.top();
                // check matching pairs
                if ((a == '(' && x == ')') ||
                    (a == '{' && x == '}') ||
                    (a == '[' && x == ']')) {
                    st.pop();
                } else {
                    return false; // mismatch
                }
            }
        }
        return st.empty();
    }
};

