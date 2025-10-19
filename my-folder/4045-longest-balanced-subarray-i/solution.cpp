class Solution {
public:
    int longestBalanced(vector<int>& nums) {\
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>st; int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(!st.count(nums[j])){
                    if(nums[j]%2==0) cnt++;
                    else cnt--;
                    st.insert(nums[j]);
                }
                if(cnt==0) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
