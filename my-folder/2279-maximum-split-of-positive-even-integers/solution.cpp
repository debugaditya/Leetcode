class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n%2==1) return {};
        vector<long long>ans; long long sum=0,i=2;
        while(sum<n){
            ans.push_back(i);
            sum+=i; i+=2; 
        }
        if(sum==n) return ans;
        sum-=ans.back(); ans.pop_back(); ans.back()+=n-sum;
        return ans;
    }
};
