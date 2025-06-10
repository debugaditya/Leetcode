class Solution {
public:
    int maxDifference(string s){
        int maxi=0,mini=INT_MAX; vector<int>mp(26,0);
        for(auto it:s) mp[it-'a']++;
        for(auto it:mp) {if(it%2==1||it==0) maxi=max(maxi,it);else mini=min(mini,it);}
        return maxi-mini;
    }
};
