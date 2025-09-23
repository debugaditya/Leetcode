class Solution {
public:
    int f(vector<vector<int>>& grid,vector<int>& limits){
        int idx=-1,maxi=INT_MIN;
        for(int i=0;i<grid.size();i++){
            if(grid[i].size()>0&&limits[i]>0){
                if(grid[i].back()>maxi) {maxi=grid[i].back(); idx=i;}
            }
        }
        limits[idx]--; grid[idx].pop_back();
        return maxi;
    }
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans=0;
        for(auto &it:grid) sort(it.begin(),it.end());
        while(k>0){
            int a=f(grid,limits);
            cout<<a<<endl;
            if(a==INT_MIN) return ans;
            ans+=a;
            k--;
        }

        return ans;
    }
};
