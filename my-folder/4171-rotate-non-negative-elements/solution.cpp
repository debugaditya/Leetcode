class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        for(auto it:nums) if(it>=0) pos.push_back(it);
        if(pos.size()==0) return nums;
        k%=pos.size();
        vector<int>rotated;
        for(int i=k;i<pos.size();i++) rotated.push_back(pos[i]);
        for(int i=0;i<k;i++) rotated.push_back(pos[i]); int j=0;
        for(auto &it:nums) if(it>=0) it=rotated[j++];
        return nums;
    }
};
