class Solution {
public:
    int trap(vector<int>& height) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        int ans=0;
        for(int i=0;i<height.size();i++){
            mp1[i]=maxi1;
            maxi1=max(maxi1,height[i]);
            mp2[height.size()-i-1]=maxi2;
            maxi2=max(maxi2,height[height.size()-i-1]);
        }
        for(int i=0;i<height.size();i++){
            if(mp1[i]>height[i]&&mp2[i]>height[i]) ans+=min(mp1[i],mp2[i])-height[i];
        }
        return ans;
    }
};
