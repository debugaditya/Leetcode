class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int p=0; vector<int>ans;
        while(n>0){
            if(n%10!=0) ans.push_back((n%10)*pow(10,p));
            n/=10; p++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
