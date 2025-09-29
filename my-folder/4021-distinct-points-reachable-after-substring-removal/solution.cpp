class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>>st; vector<int>freq(4,0);
        for(int i=0;i<k;i++){
            if(s[i]=='U') freq[0]++;
            if(s[i]=='D') freq[1]++;
            if(s[i]=='L') freq[2]++;
            if(s[i]=='R') freq[3]++;
        }
        for(int i=k-1;i<s.size();i++){
            st.insert({freq[0]-freq[1],freq[2]-freq[3]});
            if(i+1<s.size()){
                if(s[i+1]=='U') freq[0]++;
                if(s[i+1]=='D') freq[1]++;
                if(s[i+1]=='L') freq[2]++;
                if(s[i+1]=='R') freq[3]++;
            }
            if(s[i-k+1]=='U') freq[0]--;
            if(s[i-k+1]=='D') freq[1]--;
            if(s[i-k+1]=='L') freq[2]--;
            if(s[i-k+1]=='R') freq[3]--;
        }
        return st.size();
    }
};
