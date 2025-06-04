class Solution {
public:
    string answerString(string word, int n) {
        if(n==1) return word;
        int size=word.size()-n+1;
        string s=word.substr(0,size); string ans=s;
        for(int i=0;i<word.size();i++){
            s.erase(s.begin());
            if (i+size<word.size()) s.push_back(word[i+size]);
            ans=max(s,ans);
        }
        return ans;
    }
};
