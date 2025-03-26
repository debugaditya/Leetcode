class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mod=grid[0][0]%x;
        vector<int>v;
        int cnt=0;
        for(auto it:grid) for(auto it1:it){
            if(mod!=it1%x) return -1;
            v.push_back(it1);
        }
        sort(v.begin(),v.end());
        int mid=v[grid.size()*grid[0].size()/2];
        for(auto it:v) cnt+=abs(mid-it)/x;
        return cnt;
    }
};
