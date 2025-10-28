class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v; long long ans=0,sum=0;
        for(int i=0;i<nums2.size();i++) v.push_back({nums2[i],nums1[i]}); sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=v.size()-1;i>=0;i--){
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k) ans=max(ans,v[i].first*sum);
        }
        return ans;
    }
};
