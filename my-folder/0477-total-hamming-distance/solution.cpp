class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        vector<int>v(32,0); int i=0;
        while(nums[0]>0){
            if(nums[0]%2!=0) v[i]++;
            nums[0]/=2; i++;
        }
        for(int j=1;j<nums.size();j++){
            i=0;
            while(i<32){
                if(nums[j]%2==0) ans+=v[i];
                else {ans+=j-v[i]; v[i]++;}
                nums[j]/=2; i++;
            }
        }
        return ans;
    }
};
