class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>odd1(26,0),even1(26,0),odd2(26,0),even2(26,0); int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(i%2){
                odd1[s1[i]-'a']++;
                odd2[s2[i]-'a']++;
            }
            else {
                even1[s1[i]-'a']++;
                even2[s2[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++) if(odd1[i]!=odd2[i]||even1[i]!=even2[i]) return false;
        return true;
    }
};
