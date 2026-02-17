class Solution {
public:
    int checkalmost(string &temp,int l,int r){
        int maxi=1;
        while(l>=0&&r<temp.size()){
            if(temp[l]!=temp[r]){
                maxi=r-l-1;
                int l1=l-1,r1=r,l2=l,r2=r+1,len1,len2;
                while(l1>=0&&r1<temp.size()){
                    if(temp[l1]!=temp[r1]) break;
                    l1--; r1++;
                }
                maxi=max(maxi,r1-l1-1);
                while(l2>=0&&r2<temp.size()){
                    if(temp[l2]!=temp[r2]) break;
                    l2--; r2++;
                }
                maxi=max(maxi,r2-l2-1);
                return maxi;
            }
            l--; r++;
        }
        if(l<=0&&r==temp.size()) return temp.size();
        if(l<=0) return r+1;
        if(r==temp.size()) return r-l;
        return r-l-1;
    }
    int almostPalindromic(string s) {
        int ans=1;
        for(int i=0;i<s.size();i++){
            ans=max(ans,checkalmost(s,i,i));
            ans=max(ans,checkalmost(s,i,i+1));
        }
        return ans;
    }
};
