class Solution {
public:
    int f(string &s, int prev,int idx,vector<vector<int>>&dp,vector<vector<int>>&precompute){
        if(idx==s.size()-1){
            if(precompute[prev+1][idx]==1) return 1;
            else return 1000000009;
        }
        if(prev!=-1&&dp[prev][idx]!=-1) return dp[prev][idx];
        int ans=1000000009;
        if(precompute[prev+1][idx]==1) ans=1+f(s,idx,idx+1,dp,precompute);
        ans=min(ans,f(s,prev,idx+1,dp,precompute));
        if(prev!=-1) dp[prev][idx]=ans;
        return ans;
    }
    int minimumSubstringsInPartition(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        vector<vector<int>>precompute(s.size(),vector<int>(s.size(),0)); string temp="";
        for(int i=0; i<s.size(); i++){
            vector<int> freq(26,0);
            int distinct=0, maxFreq=0;
            for(int j=i; j<s.size(); j++){
                int c = s[j]-'a';
                if(freq[c]==0) distinct++;
                freq[c]++;
                maxFreq = max(maxFreq,freq[c]);
                if(maxFreq*distinct == j-i+1)
                    precompute[i][j] = 1;
            }
        }
        return f(s,-1,0,dp,precompute);      
    }
};
