class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        vector<int>ans(h.size()); stack<int>st;
        for(int i=0;i<h.size();i++){
            while(!st.empty()&&h[st.top()]<h[i]) {ans[st.top()]++; st.pop();}
            if(!st.empty()) ans[st.top()]++;
            st.push(i);
        }
        return ans;
    }
};
