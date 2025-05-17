class Solution {
public:
    void sortColors(vector<int>& n) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(auto it:n){
            if(it==0) cnt0++;
            if(it==1) cnt1++;
            if(it==2) cnt2++;
        }
        for(int i=0;i<n.size();i++){
            if(cnt0>0){
                n[i]=0;
                cnt0--;
            }
            else if(cnt1>0){
                n[i]=1;
                cnt1--;
            }
            else if(cnt2>0){
                n[i]=2;
                cnt2--;
            }
        }
        return;
    }
};
