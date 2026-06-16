class Solution {
public:
    long long power(int mid){
        if(mid==0) return 1;
        long long temp=power(mid/2);
        long long ans=temp*temp;
        if(mid%2) ans*=2;
        return ans;
    }
    long long f(long long k){
        int i=0;
        while(k>0){
            i++;
            k/=2;
        }
        return i-1;
    }
    char kthCharacter(long long k, vector<int>& o) {
        if(k==1) return 'a';
        k--; int cnt=0,i=f(k); 
        while(k>0){
            k-=power(f(k));
            if(o[i]==1) cnt++;
            i=f(k);
        }
        return (cnt%26)+'a';   
    }
};
