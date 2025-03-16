class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,int>mp;
        map<int,int>start;
        set<int>st;
        vector<int>ans(nums.size(),-1);
        vector<int>q;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()){
                ans[i]=min(i-mp[nums[i]],(int)nums.size()-i+start[nums[i]]);
                if(ans[start[nums[i]]]==-1) ans[start[nums[i]]]=min((int)nums.size()-i+start[nums[i]],i-start[nums[i]]);
                else ans[start[nums[i]]]=min(ans[start[nums[i]]],(int)nums.size()-i+start[nums[i]]);
                if(ans[mp[nums[i]]]==-1) ans[mp[nums[i]]]=min((int)nums.size()-i+mp[nums[i]],i-mp[nums[i]]);
                else ans[mp[nums[i]]]=min(ans[mp[nums[i]]],i-mp[nums[i]]);
            }
            else start[nums[i]]=i;
            mp[nums[i]]=i;
            st.insert(nums[i]);
        }
        for(auto it:queries) q.push_back(ans[it]);
        return q;
    }
};
