class Solution {
public:
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi=INT_MIN,mini=INT_MAX;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<nums.size();i++){maxi=max(maxi,nums[i][0]); mini=min(mini,nums[i][0]); pq.push({nums[i][0],i,0});}
        vector<int>ans={mini,maxi};
        while(true){
            int num=pq.top()[0],idx=pq.top()[1],col=pq.top()[2];
            if(col==nums[idx].size()-1) return ans;
            pq.pop(); pq.push({nums[idx][col+1],idx,col+1});
            mini=pq.top()[0]; maxi=max(maxi,nums[idx][col+1]);
            if(maxi-mini<ans[1]-ans[0]) ans={mini,maxi};
        }
        return ans;
    }
};
