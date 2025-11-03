class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int ans=t[0],maxi=t[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                maxi=max(t[i],maxi);
                ans+=t[i];
            }
            else{
                ans-=maxi;
                maxi=t[i]; ans+=t[i];
            }
        }
        ans-=maxi;
        return ans;
    }
};
