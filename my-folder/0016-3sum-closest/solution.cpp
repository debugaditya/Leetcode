class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the input array
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize closest sum
        int diff = abs(closestSum - target); // Initialize the difference
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1; // Start from the next element
            int k = n - 1; // Start from the last element
            while (j < k) { // Loop until j and k meet
                int sum = nums[i] + nums[j] + nums[k];
                int currDiff = abs(sum - target);
                if (currDiff < diff) { // Update closest sum and difference
                    diff = currDiff;
                    closestSum = sum;
                }
                if (sum == target) { // Exact match found, return the sum
                    return target;
                } else if (sum < target) {
                    j++; // Increment j to increase the sum
                } else {
                    k--; // Decrement k to decrease the sum
                }
            }
        }
        return closestSum;
    }
};

