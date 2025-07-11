class Solution {
public:
    void f(int &num,int &n,int &k,vector<int>&ans){
        if(to_string(num).length() == n){
            ans.push_back(num);
            return;
        }
        for(int i=0;i<10;i++){
            if(abs(num%10-i)==k){
                num*=10; num+=i;
                f(num,n,k,ans);
                num-=i; num/=10;
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans; int num=1;
        while(num<10){
            f(num,n,k,ans);
            num++;
        }
        return ans;
    }
};
