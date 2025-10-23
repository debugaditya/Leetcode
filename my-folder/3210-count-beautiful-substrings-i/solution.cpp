class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<vector<int>>mp(2001); mp[1000].push_back(-1); int sum=1000,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') sum++;
            else sum--;
            for(auto &it:mp[sum]){
                int vow=(i-it+1)/2; vow*=vow;
                if(vow%k==0) ans++; 
            }
            mp[sum].push_back(i);
        }
        return ans;
    }
};
