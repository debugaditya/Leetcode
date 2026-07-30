class Solution {
public:
    int minimumPushes(string word) {
        int ans=0,n=word.size(),unique=0; vector<int>mp(26,0); 
        for(auto &it:word) mp[it-'a']++;
        sort(mp.begin(),mp.end());
        for(int i=25;i>=0;i--){
            if(mp[i]==0) return ans;
            unique++;
            ans+=mp[i]*ceil(unique/8.0);
        }
        return ans;
    }
};
