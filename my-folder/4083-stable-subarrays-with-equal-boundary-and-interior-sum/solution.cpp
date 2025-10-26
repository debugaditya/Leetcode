class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        unordered_map<long long,long long>mp; long long sum=0,ans=0; 
        map<pair<long long,long long>,long long>freq; freq[{c[0],0}]++;
        for(int i=0;i<c.size();i++){
            sum+=c[i];
            mp[i]=sum;
            long long req=1LL*(sum-(1LL*3*c[i]));
            if(i>=2&&freq.count({c[i],req})){
                long long f=freq[{c[i],req}];
                if(c[i]==0) f--;
                if(c[i-1]==c[i]&&mp[i-2]==req) f--;
                if(f>0) ans+=f;
            }
            if(i+1<c.size()) freq[{c[i+1],sum}]++;
        }      
        return ans;
    }
};
