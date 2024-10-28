#include <bits/stdc++.h>
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long>st;
        //long long z=nums[nums.size()-1];
        vector<long long>hash(1e5 , 1);
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());  
        for(long i=nums.size()-1;i>=0;i--){
            if(st.find(pow(nums[i],2))==st.end()){
                
            }
            else{
                hash[nums[i]]+=hash[nums[i]*nums[i]];
                
            }
            st.insert(nums[i]);
        }
        long long maxi = 0;
        for(auto i : hash){
            maxi = max( maxi , i);
        }
        
        if (maxi == 1) {
            return -1;
        }
        return maxi;
    }
};
