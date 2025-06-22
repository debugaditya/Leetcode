class Solution {
public:
    int check(vector<int>& ans, int index, int sum, int i, vector<vector<int>>& dp) {
        if (sum == i) return 1;
        if (sum > i || index >= ans.size()) return 0;
        if (dp[index][sum] != -1) return dp[index][sum];

        int pick = check(ans, index, sum + ans[index], i, dp);
        int not_pick = check(ans, index + 1, sum, i, dp);
        return dp[index][sum] = pick + not_pick;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;
        for (int i = 0; i < numWays.size(); i++) {
            vector<vector<int>> dp(ans.size() + 1, vector<int>(i + 2, -1));  // dp[index][sum]
            int c = check(ans, 0, 0, i + 1, dp);

            if (c + 1 == numWays[i]) ans.push_back(i + 1);
            else if (c == numWays[i]) continue;
            else {
                cout << i << " " << c;
                return {};
            }
        }
        return ans;
    }
};

