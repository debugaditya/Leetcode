class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        if(right<3){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        vector<int>primes(right-1,1);
        for(int i=0;i<right-1;i++){
            if(primes[i]==0) continue;
            long long start = (long long)(i + 2) * (i + 2);
            for(long long j=start-2;j<right-1;j+=i+2){
                primes[j]=0;
            }
        }
        int prev=-1;
        
        int mini=INT_MAX;
        for(int i=max(0,left-2);i<=right-2;i++){
            if(primes[i]==1){
                if(prev==-1) prev=i+2;
                else{
                    if(mini>i+2-prev){
                        ans.clear();
                        ans.push_back(prev);
                        ans.push_back(i+2);
                        mini=i+2-prev;
                    }
                    prev=i+2;
                }
            }
        }
        if(ans.size()<2){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
