class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> b;
        for (int i = 0; i < s.size(); i++) {
            set<char> a;
            int num = 0;
            for (int j = i; j < s.size(); j++) {
                
                if (a.find(s[j]) == a.end()) {
                    a.insert(s[j]);
                    num++;
                } else {
                    break;
                }
            }
            b.push_back(num);
        }
        int max = 0;
        for (int k = 0; k < b.size(); k++) {
            if (b[k] > max) {
                max = b[k];
            }
        }
        return max;
    }
};

