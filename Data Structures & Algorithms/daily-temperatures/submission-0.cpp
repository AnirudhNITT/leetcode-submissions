class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> monotonic;   // store indices (not temperatures)
        vector<int> soln;

        for (int i = n - 1; i >= 0; --i) {
            // pop all indices whose temperatures are <= current temp
            while (!monotonic.empty() && temp[monotonic.top()] <= temp[i]) {
                monotonic.pop();
            }

            int days = 0;
            if (!monotonic.empty()) days = monotonic.top() - i; // distance in days

            monotonic.push(i);
            soln.push_back(days);   // keep your push_back style
        }

        reverse(soln.begin(), soln.end());
        return soln;
    }
};

