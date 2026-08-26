class Solution {
public:
    string f(string &s,int mid,int &k){
        string ans="22",temp=""; int cnt=0;
        for(int i=0;i<s.size();i++){
            temp+=s[i]; if(s[i]=='1') cnt++;
            if(i>=mid){
                if(temp[0]=='1') cnt--;
                temp.erase(temp.begin());
            }
            if(cnt==k) ans=min(ans,temp);
        }
        return ans=="22"?"":ans;
    }
    string shortestBeautifulSubstring(string s, int k) {
        string ans="22";
        int l=k,r=s.size();
        while(l<=r){
            int mid=(l+r)/2;
            string temp=f(s,mid,k);
            if(temp.size()>0){
                ans=temp;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans=="22"?"":ans;
    }
};
