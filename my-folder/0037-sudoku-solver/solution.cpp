class Solution {
public:
    bool d=false;
    void in(vector<vector<char>>& ans,vector<vector<int>>&blc,vector<vector<int>>&row,vector<vector<int>>&col){
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.size();j++){
                if(ans[i][j]!='.'){
                    int rw=i/3,cl=j/3,num=ans[i][j]-'0';
                    blc[rw*3+(cl%3)][num]=1;
                    col[j][num]=1; row[i][num]=1;
                }
            }
        }
    }
    void f(int i,int j,vector<vector<char>>& ans,vector<vector<int>>&blc,vector<vector<int>>&row,vector<vector<int>>&col){
        if(d) return;
        if(j==9) {f(i+1,0,ans,blc,row,col); return;}
        if(i==9) {d=true; return;}
        if(ans[i][j]!='.') {f(i,j+1,ans,blc,row,col); return;}
        for(int num=1;num<=9;num++){
            int rw=i/3,cl=j/3; 
            if(blc[rw*3+(cl%3)][num]||row[i][num]||col[j][num]) continue;
            col[j][num]=1; row[i][num]=1; blc[rw*3+(cl%3)][num]=1;
            ans[i][j]=num+'0';
            f(i,j+1,ans,blc,row,col);
            if(d) return;
            ans[i][j]='.';
            blc[rw*3+(cl%3)][num]=0;
            col[j][num]=0; row[i][num]=0;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>>blc(9,vector<int>(10,0)),col(9,vector<int>(10,0)),row(9,vector<int>(10,0));
        in(board,blc,row,col);
        f(0,0,board,blc,row,col);
        return;
    }
};
