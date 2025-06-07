class Solution {
public:
    string clearStars(string s) {
        struct cmp {
            bool operator()(const pair<char, int>& a,
                            const pair<char, int>& b) {
                if (a.first == b.first)
                    return a.second < b.second; // max heap on int
                return a.first > b.first;       // min heap on char
            }
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        vector<bool> deleted(s.size(), false);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                
                if (!pq.empty()) {
                    deleted[pq.top().second] = true;
                    pq.pop();
                }
                deleted[i] = true;
            } else {
                pq.push({s[i], i});
            }
        }

        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (!deleted[i]) result += s[i];
        }
        return result;
    }
};

