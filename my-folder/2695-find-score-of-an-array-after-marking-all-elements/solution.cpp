class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long retVal = 0;

        set<pair<int,int>> st;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            st.insert({nums[i],i});
        }

        while(!st.empty()){
            auto it = st.begin();

            retVal += (it->first);
            
            pair<int,int> left =  {1,-1};
            pair<int,int> right =  {n,n};
            
            if(it->second > 0){
                left = {nums[it->second-1],it->second-1};
            }

            if(it->second < n-1){
                right = {nums[it->second+1],it->second+1};
            }

            st.erase(it);
            st.erase(left);
            st.erase(right);
            
        }

        return retVal;

    }
};
