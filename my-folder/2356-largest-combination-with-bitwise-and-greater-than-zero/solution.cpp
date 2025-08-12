class Solution {
public:
    int largestCombination(vector<int>& c) {
        int ans=0,cnt=0;long long sum=0;
        while(true){
            for(auto &it:c){
                if(it%2==1) cnt++;
                it/=2;
                sum+=it;
            }
            ans=max(ans,cnt); cnt=0;
            if(sum==0) break;
            sum=0;
        }
        return ans;
    }
};
