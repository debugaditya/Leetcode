class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<long long,int>freq; for(auto it:nums) freq[it]++;
        set<vector<int>>st; sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=3;i--){
            if(i+1<nums.size()&&nums[i]==nums[i+1]) continue;
            freq[nums[i]]--;
            for(int j=i-1;j>=2;j--){
                if(j+1<i&&nums[j]==nums[j+1]) continue;
                freq[nums[j]]--;
                for(int k=j-1;k>=1;k--){
                    if(k+1<j&&nums[k]==nums[k+1]) continue;
                    freq[nums[k]]--;
                    long long tmp=1LL*target-nums[i]-nums[j]-nums[k];
                    if(freq[tmp]>0){
                        vector<int>temp={nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    freq[nums[k]]++;
                }
                freq[nums[j]]++;
            }
        }
        vector<vector<int>>ans(st.begin(),st.end()); 
        return ans;
    }
};
