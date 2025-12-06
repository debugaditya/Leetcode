class Solution {
public:
    long long mul(long long a,long long b,long long mod){
        return (__int128)a*b%mod;
    }

    long long power(long long a,long long d,long long mod){
        long long r=1;
        while(d){
            if(d&1) r=mul(r,a,mod);
            a=mul(a,a,mod);
            d>>=1;
        }
        return r;
    }

    bool isPrime(long long n){
        if(n<2) return false;
        for(long long p:{2,3,5,7,11,13,17,19,23,29})
            if(n%p==0) return n==p;
        long long d=n-1,s=0;
        while((d&1)==0){d>>=1; s++;}
        for(long long a:{2,7,61}){
            if(a%n==0) continue;
            long long x=power(a,d,n);
            if(x==1||x==n-1) continue;
            bool comp=true;
            for(int r=1;r<s;r++){
                x=mul(x,x,n);
                if(x==n-1){comp=false; break;}
            }
            if(comp) return false;
        }
        return true;
    }

    bool completePrime(int num) {
        if(num==1) return false;
        vector<int>v;
       
        string s=to_string(num),pref="",suff="";
        for(int i=0;i<s.size();i++){
            pref+=s[i];
            suff.insert(suff.begin(),s[s.size()-1-i]);
            if(!isPrime(stoi(pref))||!isPrime(stoi(suff))) return false;
        }
        return true;
    }
};

