class Solution {
public:
    vector<int>ans;
    void f(int &low, int &high,int num){
        if(num<=high&&num>=low) ans.push_back(num);
        if(num>high||num%10==9) return;
        int prev=num%10;
        num*=10; num+=prev+1;
        f(low,high,num);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++) f(low,high,i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
