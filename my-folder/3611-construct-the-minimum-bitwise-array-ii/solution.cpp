class Solution {
public:
    int f(int it){
        int maxi=-1;
        while(it>0){
            if(it%2==0) break;
            maxi++; it/=2;
        }
        return pow(2,maxi);
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            if(it%2==0) ans.push_back(-1);
            else ans.push_back(it-f(it));
        }
        return ans;
    }
};
