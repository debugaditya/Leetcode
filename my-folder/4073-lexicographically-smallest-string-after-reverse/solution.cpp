class Solution {
public:
    string lexSmallest(string s) {
        string ans="|||";
        for(int i=0;i<s.size();i++){
            string temp=s,temp1=s;
            reverse(temp1.begin(),temp1.begin()+i);
            reverse(temp.begin()+i,temp.end());
            ans=min({temp,temp1,ans});
        }
        return ans;
    }
};
