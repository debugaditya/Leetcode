class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>v(51,0); for(int i=0;i<k;i++) v[nums[i]]++; vector<int>ans; int j=k-1;
        while(j<nums.size()){
            int sum=0,cnt=0;
            priority_queue<pair<int,int>>pq;
            for(int i=0;i<51;i++) pq.push({v[i],i});
            while(!pq.empty()&&cnt<x){
                sum+=pq.top().first*pq.top().second;
                pq.pop(); cnt++;
            }
            ans.push_back(sum);
            if(j+1<nums.size()) v[nums[j+1]]++;
            v[nums[j-k+1]]--;
            j++;
        }
        return ans;
    }
};
