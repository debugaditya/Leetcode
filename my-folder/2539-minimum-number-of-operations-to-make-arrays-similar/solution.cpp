class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& t) {
        long long ans=0;
        vector<int>odd1; vector<int>odd2; vector<int>even1; vector<int>even2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) odd1.push_back(nums[i]);
            if(t[i]%2==1) odd2.push_back(t[i]);
            if(nums[i]%2==0) even1.push_back(nums[i]);
            if(t[i]%2==0) even2.push_back(t[i]);
        }
        sort(odd1.begin(),odd1.end()); sort(odd2.begin(),odd2.end());
        sort(even1.begin(),even1.end()); sort(even2.begin(),even2.end());
        for(int i=0;i<odd1.size();i++)  ans+=abs(odd1[i]-odd2[i])/2;
        for(int i=0;i<even1.size();i++) ans+=abs(even1[i]-even2[i])/2;      
        return ans/2;
    }
};
