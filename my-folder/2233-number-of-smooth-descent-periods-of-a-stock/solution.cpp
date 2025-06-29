class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0; int cnt=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i]+1==prices[i-1]) cnt++;
            else{
                ans+=1LL*cnt*(cnt+1)/2;
                cnt=1;
            }
        }
        ans+=1LL*cnt*(cnt+1)/2;
        return ans;
    }
};
