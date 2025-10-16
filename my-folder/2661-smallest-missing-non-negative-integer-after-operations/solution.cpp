class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>mp(value,0);
        for(auto &it:nums) mp[((it%value)+value)%value]++;
        int ans=0;
        while(true){
            if(mp[((ans%value)+value)%value]>0){
                mp[((ans%value)+value)%value]--;
                ans++;
            }
            else return ans;
        }
        return -1;
    }
};
