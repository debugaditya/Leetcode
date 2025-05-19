class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int cnt1=0,cnt2=0,ans=0,l=0,r=0;
        if(a[0]=='T') cnt1++;
        else cnt2++;
        while(r<a.size()){
            if(min(cnt1,cnt2)<=k){
                r++;
                if(r<a.size()&&a[r]=='T') cnt1++;
                else if(r<a.size()&&a[r]!='T') cnt2++;
            }
            else{
                ans=max(r-l,ans);
                if(a[l]=='T') cnt1--;
                else cnt2--;
                l++;
            }
        }
        ans=max(ans,r-l);
        return ans;
    }
};
