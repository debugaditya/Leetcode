class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end()); vector<int>v;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=1){
                while(nums[i]-nums[i-1]>1){
                    v.push_back(nums[i-1]+1);
                    nums[i-1]++;
                }
            }
        }
        return v;
    }
};
