class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(auto &it:patterns) if(word.find(it)<word.size()) cnt++;
        return cnt;
    }
};
