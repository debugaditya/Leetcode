class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &it:nums){
            vector<int>temp;
            while(it>0){
                temp.push_back(it%10);
                it/=10;
            }
            for(int i=temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
        }
        return ans;
    }
};
