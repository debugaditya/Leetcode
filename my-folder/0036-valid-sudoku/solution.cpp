class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                for(int k=0;k<9;k++) if(k!=i&&board[i][j]==board[k][j]) return false;
                for(int k=0;k<9;k++) if(k!=j&&board[i][j]==board[i][k]) return false;
                int x=i/3,y=j/3; x*=3; y*=3;
                for(int k=x;k<x+3;k++) for(int l=y;l<y+3;l++) {if(i==k&&l==j) continue; if(board[i][j]==board[k][l]) return false;}
            }
        }
        return true;
    }
};
