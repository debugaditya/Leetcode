class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini=INT_MAX;
        vector<int>mp(blocks.size(),0);
        int cnt=0;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='B') cnt++;
            mp[i]=cnt;
        }
        int l=0;
        int r=k-1;
        while(r<blocks.size()){
            int b=mp[r]-mp[l];
            if(blocks[l]=='B') b++;
            mini=min(k-b,mini);
            r++;
            l++;
        }
        return mini;
    }
};
