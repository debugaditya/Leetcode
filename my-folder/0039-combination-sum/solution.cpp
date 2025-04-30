class Solution {
public:
    void f(int sum,int index,vector<int>& c,int t,vector<int>&temp,vector<vector<int>>&ans){
        if(sum>t||index>=c.size()) return;
        if(sum==t){
            ans.push_back(temp);
            return;
        }
        f(sum,index+1,c,t,temp,ans);
        temp.push_back(c[index]);
        f(sum+c[index],index,c,t,temp,ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,0,c,t,temp,ans);
        return ans;
    }
};
