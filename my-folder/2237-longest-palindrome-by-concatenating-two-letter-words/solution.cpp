class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int ans=0;
        bool d=true;
        for(auto it:words) mp[it]++;
        for(auto& it:mp){
            if(it.first[0]!=it.first[1]){
                string s="";
                s+=it.first[1]; s+=it.first[0];
                ans+=4*min(it.second,mp[s]);
                it.second=0;
                mp[s]=0;
                
            }
            else{
                ans+=4*(it.second/2);
                it.second=it.second%2;
                if(d&&it.second==1){
                    ans+=2;
                    it.second=0;
                    d=false;
                }
            }
        }
        return ans;
    }
};
