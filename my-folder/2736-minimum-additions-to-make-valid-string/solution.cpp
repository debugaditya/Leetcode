class Solution {
public:
    int addMinimum(string word) {
        int ans=2-(word.back()-'a')+word[0]-'a';
        for(int i=1;i<word.size();i++){
            if((word[i]-word[i-1]+3)%3==1) continue;
            else if(word[i]==word[i-1]) ans+=2;
            else ans++;
        }
        return ans;
    }
};
