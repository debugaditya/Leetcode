class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
    int n = histo.size();
    vector<int> pse(n), nse(n); // Store indices of PSE and NSE
    stack<int> st;
    
    // Compute PSE (Previous Smaller Element)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && histo[st.top()] >= histo[i]) {
            st.pop();
        }
        pse[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    // Clear stack for next computation
    while (!st.empty()) st.pop();

    // Compute NSE (Next Smaller Element)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && histo[st.top()] >= histo[i]) {
            st.pop();
        }
        nse[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }

    // Compute max area using PSE and NSE
    int maxA = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        maxA = max(maxA, histo[i] * width);
    }

    return maxA;
}
int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        
        int maxArea = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

