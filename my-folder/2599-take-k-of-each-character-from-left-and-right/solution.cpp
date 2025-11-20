class Solution {
public:
    bool check(vector<int>&a,vector<int>&b,vector<int>&c,int mid,int k){
        int s=0,e=mid,n=a.size();
        while(e>=0){
            int cnt1=(s-1<0?0:a[s-1])+a.back()-(n-e-1<0?0:a[n-e-1]);
            int cnt2=(s-1<0?0:b[s-1])+b.back()-(n-e-1<0?0:b[n-e-1]);
            int cnt3=(s-1<0?0:c[s-1])+c.back()-(n-e-1<0?0:c[n-e-1]);
            if(cnt1>=k&&cnt2>=k&&cnt3>=k) return true;
            s++; e--;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        vector<int>b(s.size(),0); b[0]=s[0]=='b';
        vector<int>a(s.size(),0); a[0]=s[0]=='a';
        vector<int>c(s.size(),0); c[0]=s[0]=='c';
        for(int i=1;i<s.size();i++){
            b[i]=b[i-1]; a[i]=a[i-1]; c[i]=c[i-1];
            if(s[i]=='a') a[i]++; if(s[i]=='b') b[i]++; if(s[i]=='c') c[i]++;
        }
        int l=0,r=s.size(),ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(a,b,c,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
