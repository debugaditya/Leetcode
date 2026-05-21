class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>mp; int ans=0;
        for(auto &it:arr1){
            while(it>0){
                mp.insert(it);
                it/=10;
            }
        }
        for(auto &it:arr2){
            while(it>0){
                if(mp.count(it)) {ans=max(ans,(int)log10(it)+1); break;}
                it/=10;
            }
        }
        return ans;
    }
};
