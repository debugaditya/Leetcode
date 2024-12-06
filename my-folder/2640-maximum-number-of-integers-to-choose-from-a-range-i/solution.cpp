class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        int sum =0;
        set<int>st;
        for(int i=0;i<banned.size();i++){
            st.insert(banned[i]);
        }
        for(int j=1;j<=n;j++){
            if(st.find(j)==st.end()){
                sum+=j;
                if(sum<=maxSum){
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
        
    }
};
