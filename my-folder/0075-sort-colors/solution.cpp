class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
            else if(nums[i]==1){
                cnt1++;
            }
            else if(nums[i]==2){
                cnt2++;
            }
            

        }
        nums.clear();
        for(int j=1;j<=cnt;j++){
            cout<<'0';
            nums.push_back(0);
        }
        for(int k=1;k<=cnt1;k++){
            cout<<'1';
            nums.push_back(1);
        }
        for(int r=1;r<=cnt2;r++){
            cout<<'2';
            nums.push_back(2);
        }

    }
};
