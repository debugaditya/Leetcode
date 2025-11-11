class Solution {
public:
    void f(int idx,string &s,string &temp,vector<string>&ans){
        if(idx==s.size()) {ans.push_back(temp); return;}
        temp+=s[idx];
        f(idx+1,s,temp,ans);
        temp.pop_back();
        if(isalpha(s[idx])){
            if(s[idx]<='Z'){
                temp+=tolower(s[idx]);
                f(idx+1,s,temp,ans);
                temp.pop_back();
            }
            else{
                temp+=toupper(s[idx]);
                f(idx+1,s,temp,ans);
                temp.pop_back();
            }
        }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans; string temp="";
        f(0,s,temp,ans);
        return ans;
    }
};
