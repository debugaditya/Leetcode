class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int cnt=0;
        int i=0;
        while(i<s.size()){
            if(cnt<spaces.size()&&i==spaces[cnt]){
                ans+=' ';
                cnt++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};
