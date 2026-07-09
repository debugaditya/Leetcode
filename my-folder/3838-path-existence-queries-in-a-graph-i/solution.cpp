class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>v(n,0); int group=1,start=0; vector<bool>ans;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        }
        for(auto &it:queries) ans.push_back(v[it[0]]==v[it[1]]);
        return ans;
    }
};
