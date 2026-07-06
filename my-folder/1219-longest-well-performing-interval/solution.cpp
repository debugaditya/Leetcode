class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans=0,sum=0;
        for(auto &it:hours) it=(it>8?1:-1);  
        unordered_map<int,int>mp; mp[0]=-1;
        for(int i=0;i<hours.size();i++){
            sum+=hours[i];
            if(sum>0) ans=max(ans,i+1); 
            if(mp.count(sum-1)) ans=max(ans,i-mp[sum-1]); 
            //if(sum-mini>0) ans=max(ans,i-idx); 
            if(!mp.count(sum)) mp[sum]=i;
            //if(sum<mini){idx=i; mini=sum;}
        }
        return ans;
    }
};
