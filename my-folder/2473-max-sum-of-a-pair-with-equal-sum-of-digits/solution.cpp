class Solution {
public:
    int f(int n){
        int temp=n;
        int sum=0;
        while(temp>0){
            sum+=temp%10;
            temp/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        unordered_set<int>st;
        int maxi=-1;
        for(int i=nums.size()-1;i>=0;i--){
            int sum=f(nums[i]);
            if(st.find(sum)==st.end()){
                st.insert(sum);
                mp[sum]=i;
            }
            else maxi=max(maxi,nums[i]+nums[mp[sum]]); 
        }
        return maxi;
    }
};
