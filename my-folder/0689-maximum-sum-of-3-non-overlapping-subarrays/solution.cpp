class Solution {
public:
    vector<int> maxSumTripletWithDistance(vector<int>& sum, int k) {
        int n = sum.size();
        if (n < 3 || k < 1) {
            throw invalid_argument("Array must have at least three elements and k must be positive.");
        }

        vector<int> bestLeft(n, INT_MIN), leftIndex(n, -1), bestRight(n, INT_MIN), rightIndex(n, -1);

        for (int i = 0; i < n; ++i) {
            if (i - k >= 0) {
                if (bestLeft[i - 1] < sum[i - k] || (bestLeft[i - 1] == sum[i - k] && leftIndex[i - 1] > i - k)) {
                    bestLeft[i] = sum[i - k];
                    leftIndex[i] = i - k;
                } else {
                    bestLeft[i] = bestLeft[i - 1];
                    leftIndex[i] = leftIndex[i - 1];
                }
            } else if (i > 0) {
                bestLeft[i] = bestLeft[i - 1];
                leftIndex[i] = leftIndex[i - 1];
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n) {
                if (bestRight[i + 1] < sum[i + k] || (bestRight[i + 1] == sum[i + k] && rightIndex[i + 1] > i + k)) {
                    bestRight[i] = sum[i + k];
                    rightIndex[i] = i + k;
                } else {
                    bestRight[i] = bestRight[i + 1];
                    rightIndex[i] = rightIndex[i + 1];
                }
            } else if (i < n - 1) {
                bestRight[i] = bestRight[i + 1];
                rightIndex[i] = rightIndex[i + 1];
            }
        }

        int maxSum = INT_MIN;
        vector<int> result(3, -1);

        for (int j = k; j < n - k; ++j) {
            if (bestLeft[j] != INT_MIN && bestRight[j] != INT_MIN) {
                int currentSum = bestLeft[j] + sum[j] + bestRight[j];
                if (currentSum > maxSum || (currentSum == maxSum && vector<int>{leftIndex[j], j, rightIndex[j]} < result)) {
                    maxSum = currentSum;
                    result = {leftIndex[j], j, rightIndex[j]};
                }
            }
        }

        return result;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum1 = 0;
        vector<int> sum;
        for (int i = 0; i < nums.size(); i++){
            if(i>=k){
                sum.push_back(sum1);
                sum1 += nums[i] - nums[i - k];
            }
            else sum1+=nums[i];
        }
        sum.push_back(sum1);
        return maxSumTripletWithDistance(sum, k);
    }
};



