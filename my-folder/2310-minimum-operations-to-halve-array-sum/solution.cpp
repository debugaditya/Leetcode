class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq; double sum=0; int ans=0;
        for(auto it:nums){sum+=it; pq.push(it);} double dup=sum/2.0;
        while(sum>dup){
            double maxi=pq.top(); pq.pop(); ans++;
            sum-=maxi/2.0; if(sum<dup) return ans;
            pq.push(maxi/2.0);
        }
        return ans;
    }
};
