class Solution {
public:
    using ll = long long;
    const ll LIM = 1000000001LL;

    ll power_limit(ll a, int b) {
        ll ans = 1;
        while (b--) {
            if (ans > LIM / a) return LIM;
            ans *= a;
        }
        return ans;
    }

    long long C(int n,int r){
        if(r<0 || r>n) return 0;
        r=min(r,n-r);
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-r+i)/i;
            if(ans>=LIM) return LIM;
        }
        return ans;
    }

    long long ways(vector<int>& cnt){
        int rem=0;
        for(int x:cnt) rem+=x;

        long long ans=1;

        for(int i=0;i<26;i++){
            if(cnt[i]==0) continue;
            ans*=C(rem,cnt[i]);
            if(ans>=LIM) return LIM;
            rem-=cnt[i];
        }

        return ans;
    }

    string kth_string(string s, int k) {
        vector<int> cnt(26,0);
        for(char c:s) cnt[c-'a']++;

        if(ways(cnt)<k) return "";

        string ans;
        int n=s.size();

        for(int pos=0;pos<n;pos++){
            for(int c=0;c<26;c++){
                if(cnt[c]==0) continue;

                cnt[c]--;

                long long cur=ways(cnt);

                if(cur>=k){
                    ans.push_back('a'+c);
                    break;
                }

                k-=cur;
                cnt[c]++;
            }
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        if(s.size()==1) return k==1?s:"";
        vector<int>mp(26,0); char odd='?'; 
        for(auto &it:s) mp[it-'a']++; string n="";
        for(int j=0;j<26;j++){
            while(mp[j]>0){
                if(mp[j]==1){
                    odd=j+'a';
                    break;
                }
                n+=j+'a';
                mp[j]-=2;
            }
        }
        sort(n.begin(),n.end());
        //cout<<n<<endl;
        string ans=kth_string(n,k),temp=ans; 
        if(ans.size()==0) return "";
        //cout<<ans<<endl;
        reverse(temp.begin(),temp.end());
        if(odd!='?') ans+=odd; 
        ans+=temp;
        return ans;
    }
};
