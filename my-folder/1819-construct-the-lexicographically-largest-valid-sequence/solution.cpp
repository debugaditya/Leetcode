class Solution {
public:
    bool f(int n, int i, vector<int>& ans, unordered_set<int>& st) {
        if (i >= ans.size()) return st.size() == n;
        if (ans[i] != 0) return f(n, i + 1, ans, st);

        for (int j = n; j >= 1; j--) {
            if (st.find(j) != st.end()) continue;
            
            if (j == 1 || (i + j < ans.size() && ans[i + j] == 0)) {
                ans[i] = j;
                if (j != 1) ans[i + j] = j;
                st.insert(j);
                
                if (f(n, i + 1, ans, st)) return true;
                
                ans[i] = 0;
                if (j != 1) ans[i + j] = 0;
                st.erase(j);
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        unordered_set<int> st;
        f(n, 0, ans, st);
        return ans;
    }
};

