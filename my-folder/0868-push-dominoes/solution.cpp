class Solution {
public:
    string pushDominoes(string d) {
        string ans="";
        vector<int>a(d.size(),-1);
        vector<int>b(d.size(),-1);
        int prev=-1;
        for(int i=0;i<d.size();i++){
            if(d[i]=='R') prev=i;
            else if(d[i]=='L') prev=-1;
            else a[i]=prev;
        }
        prev=-1;
        for(int i=d.size()-1;i>=0;i--){
            if(d[i]=='L') prev=i;
            else if(d[i]=='R') prev=-1;
            else b[i]=prev;
        }
        for(int i=0;i<d.size();i++){
            if(d[i]=='L'||d[i]=='R') ans+=d[i];
            else{
                if(a[i]==-1&&b[i]==-1) ans+='.';
                else if(a[i]==-1) ans+='L';
                else if(b[i]==-1) ans+='R'; 
                else{
                    if(i-a[i]==b[i]-i) ans+='.';
                    else if(i-a[i]>b[i]-i) ans+='L';
                    else ans+='R';
                }
            }
        }
        return ans;
    }
};
