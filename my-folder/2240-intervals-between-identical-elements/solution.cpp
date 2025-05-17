class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        vector<long long>sum(maxi+1,0);
        vector<long long>freq(maxi+1,0);
        vector<long long>ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            ans[i]+=freq[arr[i]]*i-sum[arr[i]];
            freq[arr[i]]++;
            sum[arr[i]]+=i;
        }
        fill(sum.begin(), sum.end(), 0); fill(freq.begin(), freq.end(), 0);
        for(int i=arr.size()-1;i>=0;i--){
            ans[i]+=sum[arr[i]]-freq[arr[i]]*i;
            freq[arr[i]]++;
            sum[arr[i]]+=i;
        }
        return ans;
    }
};
