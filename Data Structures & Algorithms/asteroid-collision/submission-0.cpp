class Solution {
public:
    vector<int> asteroidCollision(vector<int>&ast) {
        stack<int> st;
        st.push(ast[0]);
        for (int i = 1; i < ast.size(); i++) {
            bool enters_st = true;

            while (!st.empty() && st.top() > 0 && ast[i] < 0) {
                int curr_top = st.top();

                if (curr_top < -ast[i]) {
                    st.pop();          // top destroyed
                    continue;
                }
                else if (curr_top == -ast[i]) {
                    st.pop();          // both destroyed
                    enters_st = false;
                    break;
                }
                else {
                    enters_st = false; // current destroyed
                    break;
                }
            }

            if (enters_st)
                st.push(ast[i]);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};