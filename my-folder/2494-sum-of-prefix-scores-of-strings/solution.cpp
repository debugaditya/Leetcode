class Solution {
public:
    const long long mod1=1e9+7; const long long mod2=1e9+9;
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<uint64_t,int>mp;
        vector<int>v(words.size(),0); 
        for(int i=0;i<words.size();i++){
            long long s1=0,s2=0,mul1=1,mul2=1;
            for(auto &it:words[i]){
                s1+=(it-'a'+1)*mul1; s1%=mod1;
                s2+=(it-'a'+1)*mul2; s2%=mod2;
                uint64_t key=((uint64_t)s1<<32)|s2;
                mp[key]++; mul1*=31; mul1%=mod1; mul2*=31; mul2%=mod2;
            }
        }
        for(int i=0;i<words.size();i++){
            long long s1=0,s2=0,mul1=1,mul2=1;
            for(int j=0;j<words[i].size();j++){
                s1+=(words[i][j]-'a'+1)*mul1; s1%=mod1;
                s2+=(words[i][j]-'a'+1)*mul2; s2%=mod2;
                uint64_t key=((uint64_t)s1<<32)|s2;
                if(mp[key]==1) {v[i]+=words[i].size()-j; break;}
                v[i]+=mp[key]; mul1*=31; mul1%=mod1; mul2*=31; mul2%=mod2;
            }
        }
        return v;
    }
};
