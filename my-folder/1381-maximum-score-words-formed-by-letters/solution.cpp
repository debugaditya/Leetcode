class Solution {
public:
    int ans=0; vector<int>mp=vector<int>(26,0); unordered_map<int,vector<int>>pre;
    void f(int i,int score,int n,vector<int>& s){
        if(i==n){ans=max(ans,score); return;}
        f(i+1,score,n,s); 
        for(int j=0;j<26;j++) if(pre[i][j]>mp[j]) return;
        for(int j=0;j<26;j++) {mp[j]-=pre[i][j]; score+=pre[i][j]*s[j];}
        f(i+1,score,n,s);
        for(int j=0;j<26;j++) {mp[j]+=pre[i][j]; score-=pre[i][j]*s[j];}
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        int n=w.size();
        for(int i=0;i<w.size();i++){
            vector<int>v(26,0);
            for(auto it:w[i]) v[it-'a']++;
            pre[i]=v;
        }
        for(auto it:l) mp[it-'a']++;
        f(0,0,n,s); 
        return ans;
    }
};
