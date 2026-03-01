class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>st={'a','e','i','o','u'};
        while(s.size()>0&&st.count(s.back())) s.pop_back();
        return s;
    }
};
