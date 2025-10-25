class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt=0,ans=0; stack<int>st; st.push(-1);
        for(auto &it:s){
            if(it=='(') st.push(cnt);
            else{
                st.pop();
                if(st.empty()) st.push(cnt);
                else ans=max(ans,cnt-st.top());
            }
            cnt++;
        }
        return ans;
    }
};
