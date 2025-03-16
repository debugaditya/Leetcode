class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int sum=0;
        int maxi=INT_MIN;
        for(auto it:nums){
            st.insert(it);
            maxi=max(maxi,it);
        }
        for(auto it:st) if(it>0) sum+=it;
        if(sum==0&&st.find(0)==st.end()) return maxi; 
        return sum;
    }
};
