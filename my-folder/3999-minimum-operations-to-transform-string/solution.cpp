class Solution {
public:
    int minOperations(string s) {
        vector<int>mp(26,0); int cnt=0;
        for(auto it:s) mp[it-'a']++;
        for(int i=1;i<26;i++){
            if(mp[i]==0) continue;
            cnt++; if(i+1<26) mp[i+1]+=mp[i];
        }
        return cnt;
    }
};
