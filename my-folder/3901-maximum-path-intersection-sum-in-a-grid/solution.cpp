class Solution {
public:
    int row(vector<vector<int>>& grid,int r){
        auto v=grid[r];
        int i=0,j=0,sum=v[0],ans=INT_MIN;
        while(j<v.size()){
            if(sum<0){
                sum-=v[i];
                i++; if(i>j) {j=i; if(j<v.size()) sum=v[j];}
            }
            else{
                j++;
                if(j<v.size()) sum+=v[j];
            }
            if(j==v.size()) continue;
            if(i==j&&(i==grid[0].size()-1||r==0||r==grid.size()-1)) continue;
            ans=max(ans,sum);
        }
        if(ans==INT_MIN){
            if(r!=0&&r!=grid.size()-1){
                return *max_element(v.begin()+1,v.end()-1);
            }
            int n=v[0]+v[1];
            for(int d=1;d<v.size();d++) n=max(n,v[d]+v[d-1]);
            //cout<<n;
            return n;
        }
        return ans;
    }
    int col(vector<vector<int>>& grid,int c){
        int i=0,j=0,sum=grid[0][c],ans=INT_MIN;
        while(j<grid.size()){
            if(sum<0){
                sum-=grid[i][c];
                i++; if(i>j) {j=i; if(j<grid.size()) sum=grid[j][c];}
            }
            else{
                j++;
                if(j<grid.size()) sum+=grid[j][c];
            }
            if((c==0||c==grid[0].size()-1||i==grid.size()-1||i==0)&&j==i) continue;
            if(j==grid.size()) continue;
            ans=max(ans,sum);
        }
        if(ans==INT_MIN){
            if(c!=0&&c!=grid[0].size()-1){
                int n=INT_MIN;
                for(int d=1;d<grid.size()-1;d++) n=max(n,grid[d][c]);
                return n;
            }
            int m=grid[0][c]+grid[1][c];
            for(int d=1;d<grid.size();d++) m=max(m,grid[d][c]+grid[d-1][c]);
            //cout<<n;
            return m;
        }
        return ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++) ans=max(ans,row(grid,i));
        for(int i=0;i<grid[0].size();i++) ans=max(ans,col(grid,i));
        return ans;
    }
};
