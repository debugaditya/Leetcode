class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>mp(n,0); int cnt=0; vector<int>ans;
        for(auto &it:queries){
            if(mp[it[0]]==0){
                if(it[0]+1<n&&mp[it[0]+1]==it[1]) cnt++;
                if(it[0]-1>=0&&mp[it[0]-1]==it[1]) cnt++;
            }
            else{
                if(it[0]+1<n&&mp[it[0]+1]==it[1]) cnt++;
                if(it[0]-1>=0&&mp[it[0]-1]==it[1]) cnt++;
                if(it[0]+1<n&&mp[it[0]+1]==mp[it[0]]) cnt--;
                if(it[0]-1>=0&&mp[it[0]-1]==mp[it[0]]) cnt--;
            }
            ans.push_back(cnt);
            mp[it[0]]=it[1];   
        }
        return ans;
    }
};
