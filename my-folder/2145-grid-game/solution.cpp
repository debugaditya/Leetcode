class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long>mp1(grid[0].size());
        vector<long long>mp2(grid[0].size());
        long long sum1=0;
        long long sum2=0;
        long long mini=LLONG_MAX;
        for(long long i=0;i<grid[0].size();i++){
            sum1+=grid[0][i];
            sum2+=grid[1][grid[0].size()-i-1];
            mp1[i]=sum1;
            mp2[grid[0].size()-i-1]=sum2;
        }
        for(long long i=0;i<grid[0].size();i++){
            mini=min(max(sum1-mp1[i],sum2-mp2[i]),mini);
        }
        return mini;
    }
};
