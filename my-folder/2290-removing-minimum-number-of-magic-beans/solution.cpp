class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum=0;
        long long mini=LLONG_MAX;
        sort(beans.begin(),beans.end());
        for(int i=beans.size()-1;i>=0;i--){
            sum+=beans[i];
        }
        for(int i=0;i<beans.size();i++){
            if(mini>sum-(beans[i]*(beans.size()-i))) mini=sum-(beans[i]*(beans.size()-i));
        }
        return mini;
    }
};
