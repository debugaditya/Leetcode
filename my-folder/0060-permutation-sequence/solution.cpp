class Solution {
public:
    void f(int n, int k,string &temp,string& ans,int &cnt){
        if(ans.size()>0) return;
        if(temp.size()==n){
            cnt++;
            if(cnt==k) ans=temp;
            return;
        }
        for(int i=1;i<=n;i++){
            char c=i+'0';
            if(temp.find(c)!=string::npos) continue;
            temp+=c;
            f(n,k,temp,ans,cnt);
            temp.pop_back();
        }
        return;
    }
    string getPermutation(int n, int k) {
        string ans="";
        string temp="";
        int cnt=0;
        f(n,k,temp,ans,cnt);
        return ans;
    }
};
