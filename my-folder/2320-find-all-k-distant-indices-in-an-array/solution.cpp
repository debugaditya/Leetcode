class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int maxi=-1; vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                for(int j=max(maxi+1,i-k);j<=min(i+k,(int)nums.size()-1);j++) ans.push_back(j);
                maxi=min(i+k,(int)nums.size()-1);
            }
        }
        return ans;
    }
};
