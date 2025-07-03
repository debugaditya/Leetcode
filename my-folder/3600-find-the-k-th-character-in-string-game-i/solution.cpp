class Solution {
public:
    char kthCharacter(int k) {
        int cnt=0; k--;
        while(k>0){
            k-=pow(2,63 - __builtin_clzll(k));
            cnt++;
        }
        return (cnt%26)+'a';
    }
};
