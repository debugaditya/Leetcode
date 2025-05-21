class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<pair<int,int>>v; for(int i=0;i<m.size();i++) for(int j=0;j<m[0].size();j++) if(m[i][j]==0) v.push_back({i,j}); for(auto it:v) {for(int i=0;i<m.size();i++) m[i][it.second]=0; for(int i=0;i<m[0].size();i++) m[it.first][i]=0;} return;
    }
};
