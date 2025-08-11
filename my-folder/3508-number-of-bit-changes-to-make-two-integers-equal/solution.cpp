class Solution {
public:
    int minChanges(int n, int k) {
        string s1="",s2=""; int ans=0;
        while(k>0){
            s1+=k%2+'0';
            k/=2;
        }
        while(n>0){
            s2+=n%2+'0';
            n/=2;
        }
        if(s1.size()>s2.size()) return -1;
        while(s2.size()!=s1.size()) s1+='0';
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='0'&&s1[i]=='1') return -1;
            if(s2[i]=='1'&&s1[i]=='0') ans++;
        }
        return ans;
    }
};
