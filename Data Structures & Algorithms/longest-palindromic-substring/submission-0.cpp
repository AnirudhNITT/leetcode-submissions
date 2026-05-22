class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int bestLen = 1;
        int start = 0;

        // length = 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length = 2
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                bestLen = 2;
            }
        }

        // length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (len > bestLen) {
                        bestLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, bestLen);
    }
};
