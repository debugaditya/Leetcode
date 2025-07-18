class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        // Store min sum of n smallest from first 2n
        priority_queue<int> leftHeap; // max heap
        vector<long long> leftSum(2 * n);
        long long left = 0;

        for (int i = 0; i < 2 * n; ++i) {
            left += nums[i];
            leftHeap.push(nums[i]);

            if (leftHeap.size() > n) {
                left -= leftHeap.top();
                leftHeap.pop();
            }

            if (leftHeap.size() == n)
                leftSum[i] = left;
        }

        // Store max sum of n largest from last 2n
        priority_queue<int, vector<int>, greater<int>> rightHeap; // min heap
        vector<long long> rightSum(2 * n + 1);
        long long right = 0;

        for (int i = nums.size() - 1; i >= n; --i) {
            right += nums[i];
            rightHeap.push(nums[i]);

            if (rightHeap.size() > n) {
                right -= rightHeap.top();
                rightHeap.pop();
            }

            if (rightHeap.size() == n)
                rightSum[i] = right;
        }

        // Find minimum difference
        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            ans = min(ans, leftSum[i] - rightSum[i + 1]);
        }

        return ans;
    }
};

