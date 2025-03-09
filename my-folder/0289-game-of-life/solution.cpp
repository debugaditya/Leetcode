class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        vector<vector<int>>d(b.size(),vector<int>(b[0].size(),0));
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                int sum=0;
                if(j-1>=0){
                    if(i-1>=0) sum+=b[i-1][j-1];
                    sum+=b[i][j-1];
                    if(i+1<b.size()) sum+=b[i+1][j-1];
                }
                if(j+1<b[0].size()){
                    if(i-1>=0) sum+=b[i-1][j+1];
                    sum+=b[i][j+1];
                    if(i+1<b.size()) sum+=b[i+1][j+1];
                }
                if(i-1>=0) sum+=b[i-1][j];
                if(i+1<b.size()) sum+=b[i+1][j];
                if(sum<2) d[i][j]=0;
                if(sum>3) d[i][j]=0;
                if(sum==3) d[i][j]=1;
                if(sum==2) d[i][j]=b[i][j];
            }
        }
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                b[i][j]=d[i][j];
            }
        }

        return;
    }
};
