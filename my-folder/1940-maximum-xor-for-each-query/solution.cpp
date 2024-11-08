#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int x = 0;
        int all_ones = (1 << maximumBit) - 1; // This gives a number with all bits set to 1 up to maximumBit

        // Calculate the prefix XOR for all elements
        for (int num : nums) {
            x ^= num;  // Cumulative XOR up to the current element
            ans.push_back(x ^ all_ones); // Maximum XOR by flipping all bits
        }

        // Reverse the answer vector to match the desired order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

