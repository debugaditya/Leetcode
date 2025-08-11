class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int maxi=-1,ans=0;
        for(int i=0;i<w.size();i++){
            if(maxi>w[i]){
                ans++;
                maxi=-1;
            }
            else maxi=w[i];
        }
        return ans;
    }
};
