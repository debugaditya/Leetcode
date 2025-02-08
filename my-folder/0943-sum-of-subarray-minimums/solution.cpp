#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> left(n), right(n);

        // Compute Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = (st.empty() ? i + 1 : i - st.top());
            st.push(i);
        }

        // Clear stack for Next Less Element (NLE)
        while (!st.empty()) st.pop();

        // Compute Next Less Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = (st.empty() ? n - i : st.top() - i);
            st.push(i);
        }

        // Calculate the sum of subarray minimums
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        
        return sum;
    }
};

