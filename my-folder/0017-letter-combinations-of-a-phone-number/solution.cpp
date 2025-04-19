class Solution {
public:
    void f(string digits,int index,string s,vector<string>&ans,unordered_map<char,vector<char>>mp){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto it:mp[digits[index]]){
            string temp=s;
            temp+=it;
            f(digits,index+1,temp,ans,mp);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        unordered_map<char,vector<char>>mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        string s="";
        f(digits,0,s,ans,mp);
        return ans;
    }
};
