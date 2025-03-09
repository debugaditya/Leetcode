class Solution {
public:
    void f(int i,int j,int color,vector<vector<int>>& image,vector<vector<int>>&visited){
        visited[i][j]=1;
        int temp=image[i][j];
        image[i][j]=color;
        if(i+1<image.size()&&visited[i+1][j]==0&&image[i+1][j]==temp) f(i+1,j,color,image,visited);
        if(i-1>=0&&visited[i-1][j]==0&&image[i-1][j]==temp) f(i-1,j,color,image,visited);
        if(j+1<image[0].size()&&visited[i][j+1]==0&&image[i][j+1]==temp) f(i,j+1,color,image,visited);
        if(j-1>=0&&visited[i][j-1]==0&&image[i][j-1]==temp) f(i,j-1,color,image,visited);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        f(sr,sc,color,image,visited);
        return image;
    }
};
