class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        for(int i=0;i<b.size();i++){
            int cnt=0;
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='#') {cnt++; b[i][j]='.';}
                else if(b[i][j]=='*'){
                    int col=j;
                    while(cnt--){
                        col--;
                        b[i][col]='#';
                    }
                    cnt=0;
                }
            }
            int col=b[0].size();
            while(cnt--){
                col--;
                b[i][col]='#';
            }
        }
        vector<vector<char>>ans(b[0].size(),vector<char>(b.size()));
        for(int i=0;i<b.size();i++) for(int j=0;j<b[0].size();j++) ans[j][b.size()-i-1]=b[i][j];
        return ans;
    }
};
