class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for (char c : text) count[c]++;

        vector<pair<char, int>> groups;
        int n = text.size();
        int i = 0;

        // Group consecutive same characters
        while (i < n) {
            char ch = text[i];
            int j = i;
            while (j < n && text[j] == ch) j++;
            groups.push_back({ch, j - i});
            i = j;
        }

        int res = 0;
        for (int i = 0; i < groups.size(); ++i) {
            auto [ch, len] = groups[i];
            // Option 1: Use full group + 1 if available
            res = max(res, min(len + 1, count[ch]));

            // Option 2: Check for merge with same char around 1 diff char
            if (i + 2 < groups.size() && groups[i + 1].second == 1 && groups[i].first == groups[i + 2].first) {
                int mergeLen = groups[i].second + groups[i + 2].second;
                if (count[ch] > mergeLen) mergeLen++; // We can add one more from outside
                res = max(res, mergeLen);
            }
        }

        return res;
    }
};




