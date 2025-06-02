class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        sort(s.begin(),s.end(),greater<int>());
        int cnt=1; string temp="";
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                if(cnt==limit){
                    temp+=s[i];
                    s.erase(s.begin()+i);
                    i--;
                }
                else cnt++;
            }
            else{
                cnt=1; string add=temp.substr(0,min((int) temp.size(),limit));
                s.insert(s.begin()+i+1,add.begin(),add.end());
                temp.erase(0,add.size());
            }
        }
        return s;
    }
};
