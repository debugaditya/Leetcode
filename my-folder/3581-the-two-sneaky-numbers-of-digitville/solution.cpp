class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> a;
        int b[100]={0};
        for(int i=0;i<nums.size();i++){
            b[nums[i]]+=1;
        }
        for(int j=0;j<100;j++){
            if(b[j]>1){
               a.push_back(j);
            }
        }
        return a;

        
    }
};
