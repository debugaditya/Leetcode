class Solution {
public:
    int ans=0;
    int f(int i,vector<int>&cost){
        if(i>cost.size()) return 0;
        int left=f(2*i,cost),right=f(2*i+1,cost);
        ans+=abs(left-right);
        return cost[i-1]+max(left,right);
    }
    int minIncrements(int n, vector<int>& cost) {
        f(1,cost);
        return ans;
    }
};
