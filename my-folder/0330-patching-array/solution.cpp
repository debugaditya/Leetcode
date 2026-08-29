class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum=1,ans=0;
        for(int i=0;i<nums.size();i++){
            while(sum<nums[i]){
                ans++;
                sum*=2;
                if(sum>n) break;
            }
            sum+=nums[i];
            if(sum>n) break;
        }
        while(sum<=n){ans++; sum*=2;}
        return ans;
    }
};
