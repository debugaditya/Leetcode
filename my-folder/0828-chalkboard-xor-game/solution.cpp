class Solution {
public:
    bool xorGame(vector<int>& nums) {
        unordered_map<int,int>mp; int cnt=0,bit=0;
        for(auto it:nums) mp[it]++;
        for(auto it:mp){
            if(it.second%2==1){
                cnt++;
                bit^=it.first;
            }
        }
        return bit==0||cnt%2==0;
    }
};
