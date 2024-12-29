class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=grid[0][i];
            for(int j=1;j<grid.size();j++){
                if(mini>=grid[j][i]){
                    ans+=mini-grid[j][i]+1;
                    grid[j][i]=mini+1;
                }
                mini=grid[j][i];
            }
        }
        return ans;
    }
};
