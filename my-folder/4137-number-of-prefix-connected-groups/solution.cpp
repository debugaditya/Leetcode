class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mp; int cnt=0;
        for(auto it:words){
            if(it.size()<k) continue;
            string pre=it.substr(0,k);
            mp[pre]++; if(mp[pre]==2) cnt++;
        }
        return cnt;
    }
};
