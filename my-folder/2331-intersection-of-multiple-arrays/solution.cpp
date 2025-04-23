class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
        vector<int>st;
        for(auto it:nums){
            for(int i=0;i<it.size();i++){
                mp[it[i]]++;
                if(mp[it[i]]==nums.size()) st.push_back(it[i]);
            }
        }
        sort(st.begin(),st.end());
        return st;
    }
};
