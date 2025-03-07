class Solution {
public:
    bool check(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        int mini=INT_MAX;
        vector<int>ans;
        int num1=-1;
        for(int i=left;i<=right;i++){
            if(check(i)){
                if(num1==-1) num1=i;
                else{
                    if(i-num1<mini){
                        mini=i-num1;
                        ans.clear();
                        ans.push_back(num1);
                        ans.push_back(i);
                    }
                    num1=i;
                }
            }
        }
        if(ans.size()<2){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
