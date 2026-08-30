class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX,idx1=-1,idx2=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]) idx1=i;
            if(mini>nums[i]) idx2=i;
            maxi=max(maxi,nums[i]); mini=min(mini,nums[i]);
        }
        int ans=min({max(idx1,idx2)+1,(int)nums.size()-min(idx1,idx2),min(idx1,idx2)+1+(int)nums.size()-max(idx1,idx2)});
        return ans;
    }
};
