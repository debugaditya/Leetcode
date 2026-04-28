class Solution {
public:
    int f(int num,vector<int>& v, int x){
        int ans=0;
        for(auto it:v) {if(abs(it-num)%x!=0) return -1; ans+=abs(it-num)/x;}
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(auto it:grid) for(auto it2:it) v.push_back(it2);
        sort(v.begin(),v.end());
        return f(v[v.size()/2],v,x);
    }
};
