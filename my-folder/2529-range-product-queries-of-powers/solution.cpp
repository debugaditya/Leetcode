class Solution {
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return modPow(a, MOD - 2);
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> power;
        int p = 0;
        int temp = n;
        while (temp > 0) {
            if (temp & 1) power.push_back(1LL << p);
            p++;
            temp >>= 1;
        }

        // mp[i] = product of first i elements (mp[0] = 1)
        vector<long long> mp(power.size() + 1, 1);
        for (int i = 0; i < (int)power.size(); i++) {
            mp[i+1] = ((__int128)mp[i] * power[i]) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &it : queries) {
            int L = it[0], R = it[1];
            long long num = mp[R+1];
            long long denom = mp[L];
            long long res = (num * modInverse(denom)) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};

