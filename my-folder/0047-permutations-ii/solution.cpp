class Solution {
public:
    void f(vector<int>& nums,vector<int>temp,int index,unordered_set<int>&st,set<vector<int>>&ans){
        st.insert(index);
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(i)!=st.end()) continue;
            temp.push_back(nums[i]);
            st.insert(i);
            f(nums,temp,i,st,ans);
            st.erase(i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        unordered_set<int>st;
        vector<int>temp;
        f(nums,temp,-1,st,ans);
        vector<vector<int>>a(ans.begin(),ans.end());
        return a;
    }
};
