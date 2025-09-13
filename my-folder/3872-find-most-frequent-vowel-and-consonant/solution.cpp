class Solution {
public:
    int maxFreqSum(string s) {
        int maxi1=0,maxi2=0; vector<int>mp(26,0);
        for(auto it:s){
            mp[it-'a']++;
            if(it=='a'||it=='e'||it=='u'||it=='o'||it=='u'||it=='i') maxi1=max(maxi1,mp[it-'a']);
            else maxi2=max(maxi2,mp[it-'a']);
        }
        return maxi1+maxi2;   
    }
};
