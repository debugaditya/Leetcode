class Solution {
public:
    unordered_map<string, int> memo;
    
    string encode(vector<int>& mp) {
        string key;
        for (int x : mp) key += to_string(x) + ",";
        return key;
    }

    int f(vector<vector<int>>& requests, vector<int>& mp, int i) {
        if (i == requests.size()) {
            for (int x : mp) if (x != 0) return INT_MIN;
            return 0;
        }

        string key = to_string(i) + "|" + encode(mp);
        if (memo.count(key)) return memo[key];

        // Option 1: Skip this request
        int notpick = f(requests, mp, i + 1);

        // Option 2: Pick this request
        mp[requests[i][0]]--;
        mp[requests[i][1]]++;
        int pick = 1 + f(requests, mp, i + 1);
        mp[requests[i][0]]++;
        mp[requests[i][1]]--;

        return memo[key] = max(pick, notpick);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> mp(n, 0);
        return f(requests, mp, 0);
    }
};

