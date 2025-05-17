class Solution {
public:
    void f(vector<int>& c, int t, int i, vector<int>& temp, set<vector<int>>& st) {
        if (t <= 0) {
            if (t == 0) st.insert(temp);
            return;
        }
        if (i == c.size()) return;

        temp.push_back(c[i]);
        f(c, t - c[i], i + 1, temp, st);
        temp.pop_back();

        int j = i + 1;
        while (j < c.size() && c[j] == c[i]) j++;
        f(c, t, j, temp, st);
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int> temp;
        set<vector<int>> st;
        sort(c.begin(), c.end());
        f(c, t, 0, temp, st);
        return vector<vector<int>>(st.begin(), st.end());
    }
};

