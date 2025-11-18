class Solution {
public:
    bool check(string &pred,string &succ){
        if(succ.size()!=1+pred.size()) return false;
        int cnt=0,j=0;
        for(int i=0;i<pred.size();i++){
            if(pred[i]!=succ[j++]) {i--; cnt++;}
            if(cnt>1) return false;
        }
        return true;
    }
    int f(int i,int prev,vector<string>& words,vector<vector<int>>&dp){
        if(i==words.size()) return 0;
        if(prev!=-1&&dp[i][prev]!=-1) return dp[i][prev];
        int pick=0,notpick=f(i+1,prev,words,dp);
        if(prev==-1||check(words[prev],words[i])) pick=1+f(i+1,i,words,dp);
        if(prev!=-1) dp[i][prev]=max(pick,notpick);
        return max(pick,notpick);
    }
    int longestStrChain(vector<string>& words) {
        priority_queue<pair<int,string>>pq;
        for(auto it:words) pq.push({it.size(),it}); words={};
        while(!pq.empty()){words.push_back(pq.top().second); pq.pop();}
        reverse(words.begin(),words.end());
        vector<vector<int>>dp(words.size(),vector<int>(words.size(),-1));
        return f(0,-1,words,dp);
    }
};
