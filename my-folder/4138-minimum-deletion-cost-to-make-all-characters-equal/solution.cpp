class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>mp(26,0); long long maxi=0,sum=0;
        for(int i=0;i<s.size();i++) {mp[s[i]-'a']+=cost[i]; maxi=max(mp[s[i]-'a'],maxi); sum+=cost[i];}
        return sum-maxi;
        
    }
};
