class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>mp(grid.size()+1,0),mp2(grid.size(),0); int idx=0,z=grid.size()-1,sum=0,ans=0;
        for(auto it:grid){
            int cnt=0;
            for(int i=it.size()-1;i>=0;i--){
                if(it[i]==1) break;
                cnt++;
            }
            mp[cnt]++; mp2[idx]=cnt;
            idx++;
        }
        for(int i=mp.size()-1;i>=0;i--){
            sum+=mp[i];
            if(sum<grid.size()-i) return -1;
        }
        for(int i = 0; i < grid.size(); i++) {
            int need = grid.size() - 1 - i;
            if (mp2[i] >= need) continue;
            int j = i + 1;
            while (j < grid.size() && mp2[j] < need) j++;
            while (j > i) {
                swap(mp2[j], mp2[j - 1]);
                ans++;
                j--;
            }
        }
        return ans;
    }
};
