class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int mult=-1;
        int num=n;
        for(int i=1;i<=k;i++){
            ans.push_back(num);
            num+=mult*(n-i);
            mult*=-1;
        }
        num=ans.back();
        if(mult==1) for(int i=1;i<=n-k;i++) ans.push_back(num-i);
        else for(int i=1;i<=n-k;i++) ans.push_back(num+i);
        return ans;
    }
};
