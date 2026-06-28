class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int>mp(arr.size()+1,0); int ans=0;
        for(auto &it:arr) mp[min(it,(int)arr.size())]++;
        for(int i=1;i<mp.size();i++){
            ans+=min(mp[i],i-ans);
        }
        return ans;
    }
};
