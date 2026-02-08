class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st; vector<long long>ans;
        for(auto it:nums){
            if(st.empty()||st.top()!=it) st.push(it);
            else{
                long long sum=it;
                while(!st.empty()&&st.top()==sum){
                    st.pop();
                    sum*=2;
                }
                st.push(sum);
            }
        }
        while(!st.empty()){ans.push_back(st.top()); st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
