class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int,int>mp; int cnt=pow(2,k),num=0,p=1;
        vector<int>powers(k);
        for(int i=0;i<k;i++){powers[i]=p; p*=2;}
        for(int i=0;i<s.size();i++){
            num+=(s[i]-'0')*powers[min(i,k-1)];
            if(i>=k-1){
                if(mp[num]==0) {cnt--; if(cnt==0) return true; mp[num]=1;}
                num/=2;
            }
        }
        return false;
    }
};
