class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        map<char,int>mp;
        int ans=s.size();
        for(auto it:s) mp[it]++;
        for(int i=1;i<=t;i++){
            int prev=mp['z'];
            ans=(prev+ans)%1000000007;
            for(int j=0;j<mp.size();j++) swap(prev,mp[j+'a']);
            mp['b']=(mp['b']+prev)%1000000007;
        }
        return ans;
    }
};
