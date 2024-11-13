class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            // Use two-pointer approach to find the range for nums[j]
            int left = lower - nums[i];
            int right = upper - nums[i];

            // Find the first position where nums[j] >= left
            int j = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            // Find the first position where nums[j] > right
            int k = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();

            ans += (k - j);
        }

        return ans;
    }
};

