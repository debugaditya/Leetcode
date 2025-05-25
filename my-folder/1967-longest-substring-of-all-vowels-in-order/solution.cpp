class Solution {
public:
    int longestBeautifulSubstring(string w) {
        vector<char>vow={'a','e','i','o','u'};
        int i=0; int l=0; int r=0; int ans=0;
        while(r<w.size()){
            if(l==r&&w[l]!='a'){l++; r++;}
            else if(l==r&&w[l]=='a'){r++; i++;}
            else if(w[r]==w[r-1]){if(w[r]=='u') ans=max(ans,r-l+1); r++;}
            else if(w[r]==vow[i]){if(i!=4) i++;else ans=max(ans,r-l+1); r++;}
            else if(w[r]!=vow[i]){l=r; i=0;}
        }
        return ans;
    }
};
