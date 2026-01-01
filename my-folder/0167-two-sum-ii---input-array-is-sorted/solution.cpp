class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<n.size();i++){
            if(mp.count(target-n[i])) return {mp[target-n[i]]+1,i+1};
            mp[n[i]]=i;
        }
        return {};
    }
};
