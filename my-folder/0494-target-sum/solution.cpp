class Solution {
public:
    void f(vector<int>& nums, int target, int sum, int i, int& ans) {

        if (i == nums.size()) {
            if (sum == target) ans++; 
            return;
        }
        f(nums, target, sum + nums[i], i + 1, ans);
        f(nums, target, sum - nums[i], i + 1, ans);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0; 
        f(nums, target, 0, 0, ans); 
        return ans;
    }
};

