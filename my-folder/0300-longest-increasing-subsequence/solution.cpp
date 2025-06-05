class Solution {
public:
    int f(vector<int>& nums, int index, int prev, vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;
        if (dp[index][prev + 1] != -1) return dp[index][prev + 1];

        int pick = 0;
        if (prev == -1 || nums[prev] < nums[index]) {
            pick = 1 + f(nums, index + 1, index, dp);
        }
        int notpick = f(nums, index + 1, prev, dp);

        return dp[index][prev + 1] = max(pick, notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // prev+1 -> range: [-1, n-1] --> [0, n]
        return f(nums, 0, -1, dp);
    }
};

