class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        vector<string> st1;
        map<int,set<string>> st2;
        for (int i = 0; i < words.size(); i++) {
            st1.push_back(words[i]);
            st2[i].insert(words[i]);
            if (words[i].size() == 1) continue;
            else if (words[i].size() == 2) {
                if (words[i][0] == words[i][1]) {
                    string s = "";
                    s += words[i][0];
                    st2[i].insert(s);
                }
                continue;
            }
            int l1 = 0;
            int l2 = words[i].size() - 2;
            int r1 = 1;
            int r2 = words[i].size() - 1;
            string s1 = words[i].substr(l1, l2 - l1 + 1);
            string s2 = words[i].substr(r1, r2 - r1 + 1);
            while (l2 >= 0) {
                if (s1 == s2) {
                    st2[i].insert(s1);
                }
                s1.pop_back();
                s2.erase(0, 1);
                l2--;
                r1++;
            }
        }
        int ans = 0;
        for (int j=0;j<words.size()-1;j++) {
            for(int k=j+1;k<words.size();k++){
                if (st2[k].find(st1[j]) != st2[k].end()) ans++;
            }
        }
        return ans;
    }
};

