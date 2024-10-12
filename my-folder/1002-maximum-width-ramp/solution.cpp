#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
        stack<int> st;

        // Fill the stack with the indices of the increasing elements
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        // Iterate from the end of the array to find the max width ramp
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};


