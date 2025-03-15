class Solution {
public:
    int f(vector<int>& nums,int i,vector<int>&visited){
        if(visited[i]==1) return 0;
        int len=0;
        int val=nums[i];
        visited[i]=1;
        while(val!=i){
            visited[val]=1;
            val=nums[val];
            len++;
        }
        return len+1;
    }
    int arrayNesting(vector<int>& nums) {
        int maxi=1;
        vector<int>visited(nums.size(),0);
        for(int i=0;i<nums.size();i++) maxi=max(f(nums,i,visited),maxi);
        return maxi;
    }
};
