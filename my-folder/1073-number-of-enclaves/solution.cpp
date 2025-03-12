class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            if(board[i][0]==1){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][board[0].size()-1]==1){
                q.push({i,board[0].size()-1});
                visited[i][board[0].size()-1]=1;
            }
        }
        for(int i=1;i<board[0].size()-1;i++){
            if(board[0][i]==1){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[board.size()-1][i]==1){
                q.push({board.size()-1,i});
                visited[board.size()-1][i]=1;
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i+1<board.size()){
                if(board[i+1][j]==1&&visited[i+1][j]==0){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
            }
            if(i-1>=0){
                if(board[i-1][j]==1&&visited[i-1][j]==0){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
            }
            if(j+1<board[0].size()){
                if(board[i][j+1]==1&&visited[i][j+1]==0){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
            }
            if(j-1>=0){
                if(board[i][j-1]==1&&visited[i][j-1]==0){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visited[i][j]==0&&board[i][j]==1) ans++;
            }
        }
        return ans;
    }
};
