class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>d;
        vector<bool>ans;
        d.push_back(0);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2==nums[i+1]%2){
                d.push_back(i+1);
            }
        }
        d.push_back(nums.size());
        for(int j=0;j<queries.size();j++){
            int k=upper_bound(d.begin(),d.end(),queries[j][0])-d.begin();
            if(k < d.size() && d[k] <= queries[j][1]){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};
