class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st; st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            while(!st.empty()&&__gcd(st.top(),x)!=1){x=lcm(x,st.top()); st.pop();}
            st.push(x);
        }
        vector<int>ans(st.size()); int j=st.size()-1;
        while(!st.empty()){
            ans[j--]=st.top();
            st.pop();
        }
        return ans;
    }
};
