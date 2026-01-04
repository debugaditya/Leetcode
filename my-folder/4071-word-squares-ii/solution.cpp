class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& w) {
        vector<vector<string>>ans; 
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w.size();j++){
                for(int k=0;k<w.size();k++){
                    for(int l=0;l<w.size();l++){
                        if(i==j||k==l||i==k||i==l||j==k||j==l) continue;
                        if(w[i][0]==w[j][0]&&w[i][3]==w[k][0]&&w[l][0]==w[j][3]&&w[l][3]==w[k][3]){
                            ans.push_back({w[i],w[j],w[k],w[l]});
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
