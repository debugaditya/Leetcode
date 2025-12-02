class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp; int ans=0; long long sum=0;
        for(auto it:points) mp[it[1]]++;
        for(auto it:mp){
            ans=(ans+sum*(it.second-1)*(it.second)/2)%1000000007;
            sum+=1LL*(it.second-1)*(it.second)/2;
        }
        return ans;
    }
};
