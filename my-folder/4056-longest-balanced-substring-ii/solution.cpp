class Solution {
public:
    int f(char a,char b, string &s){
        int cnt=0,ans=0; 
        unordered_map<int,int>mp; mp[0]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==a) cnt++;
            else if(s[i]==b) cnt--;
            else{
                cnt=0; mp.clear();
                mp[0]=i;
                continue;
            }
            if(mp.count(cnt)) ans=max(ans,i-mp[cnt]);
            else mp[cnt]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans=1,cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        ans=max({ans,f('a','b',s),f('c','b',s),f('a','c',s)});
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;

            int countAB = count[0] - count[1];
            int countAC = count[0] - count[2];

            if (mp.find({countAB, countAC}) != mp.end()) {
                ans = max(ans, i - mp[{countAB, countAC}]);
            } else {
                mp[{countAB, countAC}] = i;
            }
        }

        return ans;
    }
};
