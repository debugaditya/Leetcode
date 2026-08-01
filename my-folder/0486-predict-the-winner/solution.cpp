class Solution {
public:
    bool f(int i,int j,int turn,int &tot,int sum,vector<int>& nums){
        if(i>j) return sum>=tot-sum; 
        if(turn) return f(i+1,j,1-turn,tot,sum,nums)&&f(i,j-1,1-turn,tot,sum,nums);
        return f(i+1,j,1-turn,tot,sum+nums[i],nums)||f(i,j-1,1-turn,tot,sum+nums[j],nums);
    }
    bool predictTheWinner(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        return f(0,nums.size()-1,0,tot,0,nums);
    }
};
