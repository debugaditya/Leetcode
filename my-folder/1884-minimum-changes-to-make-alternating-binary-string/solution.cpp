class Solution {
public:
    int minOperations(string s) {
        int cnt=0,n=s.size();
        for(int i=0;i<s.size();i++) cnt+=abs(i%2-(s[i]-'0'));
        return min(cnt,n-cnt);
    }
};
