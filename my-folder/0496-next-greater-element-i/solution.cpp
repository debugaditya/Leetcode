class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;

        // Iterate from right to left over nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();  // Remove smaller elements as they are not useful
            }
            if (!st.empty()) {
                mp[nums2[i]] = st.top();  // Store the next greater element
            } else {
                mp[nums2[i]] = -1;  // No greater element found
            }
            st.push(nums2[i]);  // Push current element to stack
        }

        // Find results for nums1
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};

