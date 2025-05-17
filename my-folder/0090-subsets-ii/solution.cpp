class Solution {
public:
    void f(vector<int>& nums,int i,vector<int>&temp,set<vector<int>>&st){
        if(i==nums.size()){st.insert(temp); return;}
        temp.push_back(nums[i]);
        f(nums,i+1,temp,st);
        temp.pop_back();
        f(nums,i+1,temp,st);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        f(nums,0,temp,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
