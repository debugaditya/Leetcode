class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt=1,ans=0; vector<int>mp(colors.size(),0);
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]) cnt++;
            else cnt=1;
            if(i>=k-1) mp[i]=cnt;
        }
        for(int i=0;i<k;i++){
            if(colors[i]!=colors[(i-1+colors.size())%colors.size()]) cnt++;
            else cnt=1;
            mp[i]=cnt;
        }
        for(auto it:mp) if(it>=k) ans++;
        return ans;
    }
};
