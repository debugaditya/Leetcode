class Solution {
public:
    void f(vector<int>& nums,int index,int x,int &sum){
        if(index==nums.size()){
            sum+=x;
            return;
        }
        f(nums,index+1,x^nums[index],sum);
        f(nums,index+1,x,sum);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        f(nums,0,0,sum);
        return sum;
    }
};
