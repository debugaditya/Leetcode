class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto &it:queries){
            for(int i=it[0];i<=it[2];i++){
                ans[i][it[1]]++;
                if(it[3]+1<n) ans[i][it[3]+1]--;
            }
        }
        for(auto &it:ans) for(int i=1;i<it.size();i++) it[i]+=it[i-1];
        return ans;
    }
};
