class Solution {
public:
    void f(int n,string &s,vector<string>&ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        s+="1";
        f(n,s,ans);
        s.pop_back();
        if(s.size()==0||s.back()=='1'){
            s+="0";
            f(n,s,ans);
            s.pop_back();
        }
        return;
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s="";
        f(n,s,ans);
        return ans;
    }
};
