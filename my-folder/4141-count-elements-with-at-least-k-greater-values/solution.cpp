class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        if(k==0) return nums.size();
        sort(nums.begin(),nums.end()); 
        int i=nums.size()-k-1;
        while(i>=0&&nums[i]==nums[i+1]){
            i--;
        }
        return i+1;
    }
};
