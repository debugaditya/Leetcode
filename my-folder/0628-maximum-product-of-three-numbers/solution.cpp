class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi1=-1001,maxi2=-1001,maxi3=-1001,mini1=1001,mini2=1001;
        for(auto &it:nums){
            if(it>=maxi1){
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=it;
            }
            else if(it>=maxi2){
                maxi3=maxi2;
                maxi2=it;
            }
            else if(it>=maxi3) maxi3=it;
            if(it<=mini1){
                mini2=mini1;
                mini1=it;
            }
            else if(it<=mini2) mini2=it;
        }
        return max(maxi1*maxi2*maxi3,maxi1*mini1*mini2);
    }
};
