class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxCap) {
        int count = 0, i = 0;
        while (i < nums.size()) {
            if (nums[i] <= maxCap) {
                count++;
                i += 2;  // Move to the next valid pick
                if (count >= k) return true;
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

