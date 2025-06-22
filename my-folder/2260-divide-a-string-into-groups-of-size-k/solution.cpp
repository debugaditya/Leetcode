class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans(ceil(1.0*s.size()/k));
        for(int i=0;i<s.size();i++) ans[i/k]+=s[i];
        while(ans.back().size()<k) ans.back()+=fill;
        return ans;
    }
};
