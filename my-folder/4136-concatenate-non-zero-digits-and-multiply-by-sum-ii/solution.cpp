class Solution {
public:
    const long long MOD = 1000000007;

    long long modpow(long long a, long long b){
        long long r = 1;
        while(b > 0){
            if(b & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return r;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        unordered_map<int,long long> sum, num, cnt;
        sum[-1] = 0; cnt[-1] = 0; num[-1] = 0;
        vector<int> ans;

        for(int i = 0; i < s.size(); i++){
            sum[i] = (sum[i-1] + s[i] - '0') % MOD;
            num[i] = (s[i]=='0') ? num[i-1] : (num[i-1] * 10 + (s[i]-'0')) % MOD;
            cnt[i] = cnt[i-1] + (s[i] == '0' ? 0 : 1);
        }

        for(auto &it : queries){
            long long L = it[0], R = it[1];
            long long totalNum = num[R];
            long long leftNum = num[L-1];
            long long p = modpow(10, cnt[R] - cnt[L-1]);
            long long seg = (totalNum - (leftNum * p) % MOD + MOD) % MOD;
            long long ss = (sum[R] - sum[L-1] + MOD) % MOD;

            ans.push_back( (ss * seg) % MOD );
        }
        return ans;
    }
};

