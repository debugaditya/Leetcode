class Solution {
public:
    vector<vector<string>>ans;
    vector<string>board;
    void f(int i,vector<int>&dia1,vector<int>&dia2,vector<int>&col){
        if(i==col.size()){ans.push_back(board); return;}
        for(int j=0;j<col.size();j++){
            if(col[j]||dia1[i+j]||dia2[j-i+col.size()-1]) continue;
            col[j]=1; dia1[i+j]=1; dia2[j-i+col.size()-1]=1;
            string temp=string(col.size(),'.');
            temp[j]='Q'; board.push_back(temp);
            f(i+1,dia1,dia2,col);
            board.pop_back();
            col[j]=0; dia1[i+j]=0; dia2[j-i+col.size()-1]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int>dia1(2*n-1,0);
        vector<int>dia2(2*n-1,0);
        vector<int>col(n,0);
        f(0,dia1,dia2,col);
        return ans;
    }
};
