class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
        int ans=0,f=st,b=st;
        while(ans<=words.size()/2){
            if(words[f]==target||words[b]==target) return ans;
            ans++;
            f=(f+1)%words.size();
            b=(b-1+words.size())%words.size();
        }
        return -1;
    }
};
