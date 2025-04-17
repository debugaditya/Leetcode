class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        long long ans=0;
        long long pairs=0;
        unordered_map<int,int>freq;
        freq[nums[0]]++;
        int l=0;
        int r=0;
        while(r<nums.size()){
            if(pairs<k){
                r++;
                pairs+=freq[nums[r]];
                freq[nums[r]]++;
            }
            else{
                ans+=nums.size()-r;
                freq[nums[l]]--;
                pairs-=freq[nums[l]];
                l++;
            }
        }
        return ans;
    }
};
