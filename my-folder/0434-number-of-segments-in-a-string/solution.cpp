class Solution {
public:
    int countSegments(string s) {
        if(s.size()==0) return 0;
        int cnt=0;
        for(int i=1;i<s.size();i++) if(s[i]==' '&&s[i-1]!=' ') cnt++;
        if(s.back()!=' ') cnt++;
        return cnt;
    }
};
