class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "" || curr == "."){}
                else if (curr == "..") {
                    if (!st.empty())st.pop();
                }
                else {
                    st.push(curr);
                    
                }
                curr = "";
            }
            else curr.push_back(path[i]);
        }
        vector<string> dirs;
        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }
        reverse(dirs.begin(), dirs.end());
        string ans = "";
        for (string dir : dirs) {
            ans += "/" + dir;
        }
        return ans.empty() ? "/" : ans;
    }
};