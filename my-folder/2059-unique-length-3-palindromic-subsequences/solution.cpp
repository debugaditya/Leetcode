class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        unordered_map<char,pair<int,int>>mp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                mp[s[i]].first= i;
            }
            mp[s[i]].second=i;
        }
        for(auto it:mp){
            int start = it.second.first;
            int end = it.second.second;
            if(end-start>1){
                set<char> st2(s.begin() + start + 1, s.begin() + end);
                ans+=st2.size();
            }
        }
        return ans;
    }
};
