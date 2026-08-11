class Solution {
public:
    int ans=0;
    void f(int i,vector<int>&dia1,vector<int>&dia2,vector<int>&col){
        if(i==col.size()){ans++; return;}
        for(int j=0;j<col.size();j++){
            if(col[j]||dia1[i+j]||dia2[j-i+col.size()-1]) continue;
            col[j]=1; dia1[i+j]=1; dia2[j-i+col.size()-1]=1;
            f(i+1,dia1,dia2,col);
            col[j]=0; dia1[i+j]=0; dia2[j-i+col.size()-1]=0;
        }
    }
    int totalNQueens(int n) {
        vector<int>dia1(2*n-1,0),dia2(2*n-1,0),col(n,0);
        f(0,dia1,dia2,col);
        return ans;
    }
};
