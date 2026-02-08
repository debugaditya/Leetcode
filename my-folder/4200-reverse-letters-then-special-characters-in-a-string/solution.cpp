class Solution {
public:
    string reverseByType(string s) {
        string a="",sp="",ans=""; int i=0,j=0;
        for(auto it:s){
            if(isalpha(it)) a+=it;
            else sp+=it;
        }
        if(a.size()>0) reverse(a.begin(),a.end());
        if(sp.size()>0) reverse(sp.begin(),sp.end());
        if(a.size()==0) return sp;
        if(sp.size()==0) return a;
        for(auto it:s){
            if(isalpha(it)) ans+=a[i++];
            else ans+=sp[j++];
        }
        return ans;
    }
};
