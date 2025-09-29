class Solution {
public:
    long long splitArray(vector<int>& nums) {
        if(nums.size()==2) return abs(nums[0]-nums[1]);
        long long s1=nums[0],s2=nums.back();
        int i=0,j=nums.size()-1;
        while(i<nums.size()-1&&j>0&&(nums[i]<nums[i+1]||nums[j]<nums[j-1])){
            if(nums[i]<nums[i+1]){
                s1+=nums[i+1];
                i++;
            }
            if(nums[j]<nums[j-1]){
                s2+=nums[j-1];
                j--;
            } 
        }
        if(j-i>1) return -1;
        if(j==i+1) return abs(s1-s2);
        return min(abs((s1-nums[i])-s2),abs((s2-nums[i])-s1));
    }
};
