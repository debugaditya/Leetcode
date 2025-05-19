class Solution {
public:
    bool isCovered(vector<vector<int>>& r, int left, int right) {
        vector<int>v(52,0);
        int sum=0;
        for(auto it:r){
            v[it[0]]++;
            v[it[1]+1]--;
        }
        for(int i=0;i<v.size();i++){sum+=v[i]; v[i]=sum; if(left<=i&&i<=right&&v[i]==0){return false;}}
        return true;
    }
};
