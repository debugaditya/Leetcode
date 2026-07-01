class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int>freq; for(auto it:nums) freq[it]++;
        set<vector<int>>st; sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
            if(i+1<nums.size()&&nums[i]==nums[i+1]) continue;
            freq[nums[i]]--;
            for(int j=i-1;j>=0;j--){
                if(j+1<i&&nums[j]==nums[j+1]) continue;
                freq[nums[j]]--;
                if(freq[-nums[i]-nums[j]]>0){
                    int mini=min({nums[i],nums[j],-nums[i]-nums[j]});
                    int maxi=max({nums[i],nums[j],-nums[i]-nums[j]});
                    st.insert({mini,-maxi-mini,maxi});
                }
                freq[nums[j]]++;
            }
            freq[nums[i]]=0;
        }
        vector<vector<int>>ans(st.begin(),st.end()); 
        return ans;
    }
};
