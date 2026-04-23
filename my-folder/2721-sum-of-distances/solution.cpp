class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        unordered_map<int,long long>sum;
        unordered_map<int,long long>freq;
        vector<long long>ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            ans[i]+=freq[arr[i]]*i-sum[arr[i]];
            freq[arr[i]]++;
            sum[arr[i]]+=i;
        }
        sum.clear(); freq.clear();
        for(int i=arr.size()-1;i>=0;i--){
            ans[i]+=freq[arr[i]]*(arr.size()-1-i)-sum[arr[i]];
            freq[arr[i]]++;
            sum[arr[i]]+=arr.size()-1-i;
        }
        return ans;
    }
};
