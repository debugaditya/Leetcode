class Solution {
public:
    int f(int idx){
        long long ans=1;
        while(idx--){
            ans*=2;
            ans%=1000000007;
        }
        return ans;
    }
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++; int cnt=0,idx=-1; unordered_set<int>st;
        for(auto it:nums){
            mp[it]--; st.insert(it);
            if(mp[it]==0) cnt++;
            if(cnt==st.size()) idx++;
        }
        return f(idx);
    }
};
