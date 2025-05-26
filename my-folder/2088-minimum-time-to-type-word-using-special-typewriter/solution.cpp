class Solution {
public:
    int minTimeToType(string word) {
        char prev='a'; int ans=0;
        for(auto it:word){
            ans+=min(abs(it-prev),26-abs(it-prev))+1;
            prev=it;
        }
        return ans;
    }
};
