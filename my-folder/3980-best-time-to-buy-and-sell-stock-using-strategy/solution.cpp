class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<long long>mp(prices.size(),0); long long sum=0; vector<long long>mp2(prices.size(),0);
        for(int i=0;i<k;i++) sum+=prices[i]*strategy[i];
        for(int i=k-1;i<prices.size();i++){
            mp[i-k+1]=sum;
            sum-=prices[i-k+1]*strategy[i-k+1];
            if(i+1<prices.size()) sum+=prices[i+1]*strategy[i+1];
        }
        long long profit=0,ans=0;
        for(int i=0;i<prices.size();i++) profit+=prices[i]*strategy[i]; 
        ans=profit; sum=0; 
        for(int i=0;i<k;i++) if(i>=k/2) sum+=prices[i];
        for(int i=k-1;i<prices.size();i++){
            mp2[i-k+1]=sum;
            sum-=prices[i-k/2+1];
            if(i+1<prices.size()) sum+=prices[i+1];
        }
        for(int i=0;i<prices.size();i++) ans=max(ans,profit-mp[i]+mp2[i]);
        return ans;
    }
};
