class Solution {
public:
    bool isSubsequence(const string &s, const string &pattern) {
        int i = 0;
        for (char c : s) {
            if (c == pattern[i]) i++;
            if (i == pattern.size()) return true;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push("");
        string result = "";
        unordered_map<string, bool> visited;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (char ch = 'a'; ch <= 'z'; ++ch) {
                string next = curr + ch;
                if (visited.count(next)) continue;

                string repeated = "";
                for (int i = 0; i < k; ++i) repeated += next;

                if (isSubsequence(s, repeated)) {
                    visited[next] = true;
                    q.push(next);

                    if (next.size() > result.size()) result = next;
                    else if (next.size() == result.size()) result = max(result, next);
                }
            }
        }

        return result;
    }
};

