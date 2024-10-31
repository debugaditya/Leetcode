class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int b=nums.size();
        int k=0;
        for(int i=0;i<b;i++){
            if(nums[i]==val){
                nums.erase(nums.begin() + i);
                b--;
                i--;
            }
            else{
                k++;
            }
        }
        return k;
        
    }
};
