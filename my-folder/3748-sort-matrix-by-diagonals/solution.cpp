class Solution {
public:
    void f(vector<vector<int>>& grid,int i,int j){
        vector<int>v; int row=i,col=j;
        while(i<grid.size()&&j<grid.size()) v.push_back(grid[i++][j++]); 
        if(col==0) sort(v.begin(),v.end());
        else if(row==0) sort(v.begin(),v.end(),greater<int>()); 
        i--; j--;
        for(auto it:v) grid[i--][j--]=it;
        return;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++) f(grid,i,0);
        for(int j=1;j<grid.size();j++) f(grid,0,j);
        return grid;
    }
};
