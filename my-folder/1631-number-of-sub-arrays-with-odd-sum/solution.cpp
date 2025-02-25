class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int const MOD=1e9+7;
        int even=1;
        int odd =0;
        long long ans=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==1){
                ans+=even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
        }
        return ans%MOD;
    }
};
