class Solution {
public:
    set<vector<int>>st;
    long long factorial(int n){
        long long ans=1; int i=1;
        while(i<=n){
            ans*=i;
            i++;
        }
        return ans;
    }
    long long g(vector<int>&mp,int n){
        long long a=factorial(n);
        for(auto it:mp) a/=factorial(it);
        return a;
    }
    void f(int &n, int &k,string &num,long long &ans,vector<int>&mp){
        if(num[0]=='0') return;
        if(num.size()>n/2&&num.back()!=num[n-num.size()]) return; 
        if(num.size()==n){
            if(st.find(mp)==st.end()&&stoll(num)%k==0){
                ans+=g(mp,n);
                if(mp[0]>0){
                    mp[0]--;
                    ans-=g(mp,n-1);
                    mp[0]++;
                }
                st.insert(mp);
            }
            return;
        }
        for(int i=0;i<=9;i++){
            num+=i+'0';
            mp[i]++;
            f(n,k,num,ans,mp);
            mp[i]--;
            num.pop_back();
        }
        return;
    }
    long long countGoodIntegers(int n, int k) {
        string num="";
        vector<int>mp(10,0);
        long long ans=0;
        f(n,k,num,ans,mp);
        return ans;
    }
};
