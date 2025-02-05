class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int temp=-1;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(cnt>2) return false;
            if(s1[i]!=s2[i]){
                cnt++;
                if(temp!=-1&&(s1[temp]!=s2[i]||s2[temp]!=s1[i])) return false;
                temp=i;
            }
        }
        if(cnt==1) return false;
        return true;
    }
};
