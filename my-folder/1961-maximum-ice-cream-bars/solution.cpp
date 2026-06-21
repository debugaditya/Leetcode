class Solution {
public:
    void sort(vector<int>&cost){
        int maxi=*max_element(cost.begin(),cost.end());
        vector<int>mp(maxi+1,0);
        for(auto it:cost) mp[it]++; int idx=0;
        for(int i=1;i<=maxi;i++) while(mp[i]>0) {cost[idx++]=i; mp[i]--;} 
    }
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs); int ans=0;
        for(auto it:costs){
            if(it>coins) return ans;
            ans++; coins-=it;
        }
        return ans;
    }
};
