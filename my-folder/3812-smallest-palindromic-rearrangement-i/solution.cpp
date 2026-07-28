class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>mp(26,0);
        for(auto &it:s) mp[it-'a']++; int i=0;
        for(int j=0;j<26;j++){
            while(mp[j]>0){
                if(mp[j]>1){
                    s[i]=j+'a';
                    s[s.size()-1-i]=s[i];
                    mp[j]-=2; i++;
                }
                else {s[(s.size()-1)/2]=j+'a'; mp[j]--;}
            }
        }
        return s;
    }
};
