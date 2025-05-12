class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        vector<int>mp(10,0);
        vector<int>ans;
        for(auto it:d) mp[it]++;
        for(int i=0;i<10;i+=2){
            if(mp[i]==0) continue;
            mp[i]--;
            for(int j=0;j<10;j++){
                if(mp[j]==0) continue;
                mp[j]--;
                for(int k=1;k<10;k++){
                    if(mp[k]==0) continue;
                    mp[k]--;
                    int num=100*k+10*j+i;
                    ans.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
