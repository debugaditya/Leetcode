class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v; long long sum=0; vector<long long>ans(nums1.size()); priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums1.size();i++) v.push_back({nums1[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(i>0&&v[i].first==v[i-1].first) ans[v[i].second]=ans[v[i-1].second];
            else ans[v[i].second]=sum;
            if(pq.size()<k){sum+=nums2[v[i].second]; pq.push(nums2[v[i].second]);}
            else{
                if(nums2[v[i].second]>pq.top()){sum+=nums2[v[i].second]-pq.top(); pq.pop(); pq.push(nums2[v[i].second]);}
            }
        }
        return ans;
    }
};
