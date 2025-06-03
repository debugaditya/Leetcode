class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid[0].size(); int m=grid.size(); vector<int>ans;
        int i=0,j=0,cnt=0;
        while(i<m){
            if(cnt%2==0) ans.push_back(grid[i][j]);
            if(j==n-1&&i%2==0||j==0&&i%2==1) i++;
            else j+=1-2*(i%2);
            cnt++;
        }
        return ans;
    }
};
