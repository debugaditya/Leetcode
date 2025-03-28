class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>freq1;
        map<int,int>freq2;
        map<int,int>mp1;
        map<int,int>mp2;
        int dom1;
        int dom2;
        for(int i=0;i<nums.size();i++){
            freq1[nums[i]]++;
            if(freq1[nums[i]]>(i+1)/2) dom1=nums[i];
            if(freq1[dom1]>(i+1)/2) mp1[i]=dom1;
            else mp1[i]=-1;
        }
        for(int i=nums.size()-1;i>=0;i--){
            freq2[nums[i]]++;
            if(freq2[nums[i]]>(nums.size()-i)/2) dom2=nums[i];
            if(freq2[dom2]>(nums.size()-i)/2) mp2[i]=dom2;
            else mp2[i]=-1;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(mp1[i]==-1||mp2[i+1]==-1) continue;
            if(mp1[i]==mp2[i+1]) return i;
        }
        return -1;
    }
};
