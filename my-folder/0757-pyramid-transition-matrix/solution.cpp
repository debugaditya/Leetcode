class Solution {
public:
    unordered_map<string,bool> dp;

    bool f(vector<vector<vector<int>>>& mp, const string& b, string& s) {
        if (b.size() == 1) return true;

        string key = b + "|" + s;
        if (dp.count(key)) return dp[key];

        if (s.size() == b.size() - 1) {
            string next = s;
            string empty = "";
            return dp[key] = f(mp, next, empty);
        }

        int i = s.size();

        if (mp[b[i]-'A'][b[i+1]-'A'].empty())
            return dp[key] = false;

        for (auto it : mp[b[i]-'A'][b[i+1]-'A']) {
            s.push_back(it + 'A');
            if (f(mp, b, s))
                return dp[key] = true;
            s.pop_back();
        }

        return dp[key] = false;
    }

    bool pyramidTransition(string b, vector<string>& allowed) {
        vector<vector<vector<int>>> mp(6, vector<vector<int>>(6));
        for (auto it : allowed)
            mp[it[0]-'A'][it[1]-'A'].push_back(it[2]-'A');

        string s = "";
        return f(mp, b, s);
    }
};

