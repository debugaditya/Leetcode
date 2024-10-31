class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int mini=INT_MAX, maxi=INT_MIN;
        for(int &num:nums) {
            mini=min(mini, num);
            maxi=max(maxi, num);
        }
        vector<int> vec(maxi-mini+1, 0);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int diff=abs(nums[i]-nums[j]);
                vec[diff]++;
            }
        }
        for(int i=0; i<vec.size(); i++) {
            k-=vec[i];
            if(k<=0) return i;
        }
        return -1;
    }
};
