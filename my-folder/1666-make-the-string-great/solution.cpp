class Solution {
public:
    string makeGood(string s) {
        string ans=""; ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(ans.size()==0) ans+=s[i];
            else if(ans.back()!=s[i]&&toupper(s[i])==toupper(ans.back())) ans.pop_back();
            else ans+=s[i];
        }
        return ans;
    }
};
