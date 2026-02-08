class Solution {
public:
    bool check(string s1,string s2){
        for(int i=0;i<s1.size();i++) if(((s1[i]-s2[i])%26+26)%26!=((s1[0]-s2[0])%26+26)%26) {return false;}
        return true;
    }
    long long dfs(int i,vector<string>& words,vector<int>& vis){
        if(vis[i]==1) return 0;
        vis[i]=1; long long ans=0;
        for(int j=i+1;j<words.size();j++){
            if(vis[j]==0&&check(words[i],words[j])) {ans+=1+dfs(j,words,vis); break;}
        }
        return ans==0?0:ans;
    }
    long long countPairs(vector<string>& words) {
        vector<int>vis(words.size(),0); long long ans=0;
        for(int i=0;i<words.size();i++) if(vis[i]==0) {long long t=dfs(i,words,vis); ans+=1LL*t*(t+1)/2;}
        return ans;
    }
};
