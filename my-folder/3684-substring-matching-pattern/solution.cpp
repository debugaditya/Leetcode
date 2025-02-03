class Solution {
public:
    bool hasMatch(string s, string p) {
        bool d=true;
        string s1="";
        string s2="";
        for(int i=0;i<p.size();i++){
            if(p[i]!='*'&&d) s1+=p[i];
            else if(p[i]!='*'&&!d) s2+=p[i];
            else d=false;
        }
        bool d1= false;
        bool d2=false;
        int l=s1.size()-1;
        int r=s.size()-s2.size();
        string c1=s.substr(0,s1.size());
        string c2=s.substr(r,s2.size());
        while(l<r){
            if(c1==s1) d1=true;
            if(c2==s2) d2=true;
            if(d1&&d2) return true;
            if(r==0&&!d2) return false;
            if(l==s.size()-1&&!d1) return false;
            if(!d2){
                c2.pop_back();
                c2.insert(c2.begin(),s[r-1]);
            }
            if(!d1){
                c1.erase(c1.begin());
                c1.push_back(s[l+1]);
            }
            if(!d1) l++;
            if(!d2) r--;
        }
        return false;
    }
};
