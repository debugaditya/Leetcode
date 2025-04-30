class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto it:nums) if((int)log10(it)%2==1) cnt++;
        return cnt;
    }
};
