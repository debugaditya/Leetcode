class Solution {
public:
    int dist(const string& a, const string& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) 
            if (a[i] != b[i]) cnt++;
        return cnt;
    }

    vector<vector<vector<int>>> dp; 
    vector<vector<bool>> vis;

    vector<int> f(int index, vector<string>& w, vector<int>& g, int last) {
        if (index == g.size()) return {};
        if (vis[index][last+1]) return dp[index][last+1];
        vis[index][last+1] = true;

        // skip
        vector<int> best = f(index+1, w, g, last);

        // take
        if (last == -1 || 
           (g[last] != g[index] && 
            w[last].size() == w[index].size() && 
            dist(w[last], w[index]) == 1)) 
        {
            vector<int> take = f(index+1, w, g, index);
            take.insert(take.begin(), index); // prepend current
            if (take.size() > best.size()) best = take;
        }

        return dp[index][last+1] = best;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = w.size();
        dp.assign(n, vector<vector<int>>(n+1));
        vis.assign(n, vector<bool>(n+1, false));

        vector<int> ans = f(0, w, g, -1);

        vector<string> res;
        for (int i : ans) res.push_back(w[i]);
        return res;
    }
};

