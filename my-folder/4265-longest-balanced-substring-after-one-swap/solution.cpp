class Solution {
public:
    int longestBalanced(string s) {
        int total_zeroes=count(s.begin(),s.end(),'0'),ans=0;
        unordered_map<int,int>mp,mp2; int sum=0; mp[0]=-1;
        for(int i=0;i<s.size();i++){
            sum+=s[i]=='1'?1:-1;
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum]);
                if(!mp2.count(sum)) mp2[sum]=i;
            }
            if(mp.count(sum-2)){
                int zeroes=(i-mp[sum-2]-2)/2;
                if(zeroes<total_zeroes) ans=max(ans,i-mp[sum-2]);
                else if(mp2.count(sum-2)) ans=max(ans,i-mp2[sum-2]);
            }
            if(mp.count(sum+2)){
                int ones=(i-mp[sum+2]-2)/2;
                if(ones<s.size()-total_zeroes) ans=max(ans,i-mp[sum+2]);
                else if(mp2.count(sum+2)) ans=max(ans,i-mp2[sum+2]);
            }
            if(!mp.count(sum)) mp[sum]=i;
        }
        return ans;
    }
};
