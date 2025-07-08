class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>>& events, int i, int k, vector<int>& nextIndex) {
        if (k == 0 || i == events.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int notPick = f(events, i + 1, k, nextIndex);
        int pick = events[i][2] + f(events, nextIndex[i], k - 1, nextIndex);
        return dp[i][k] = max(pick, notPick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> nextIndex(n, n);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1, ans = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (events[m][0] > events[i][1]) {
                    ans = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            nextIndex[i] = ans;
        }
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return f(events, 0, k, nextIndex);
    }
};

