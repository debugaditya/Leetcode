class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            int idx=-1,sum=0;
            for(int j=0;j<mat[0].size();j++){sum+=mat[i][j]; if(mat[i][j]) idx=j;}
            if(sum==1) {for(int j=0;j<mat.size();j++) sum+=mat[j][idx]; if(sum==2) ans++;}
        }
        return ans;
    }
};
