class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int size=0,ans=0,l=0,r=0;
        while(r<s.size()){
            if(st.find(s[r])!=st.end()){
                ans=max(size,ans);
                st.erase(s[l]);
                l++;
                size--;
            }
            else{
                st.insert(s[r]);
                size++;
                r++;
            }
        } 
        ans=max(size,ans);      
        return ans;
    }
};
