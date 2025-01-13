class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        int mini=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2==1) mini++;
            else mini+=2;
        }
        return mini;
    }
};
