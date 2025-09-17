class Solution {
public:
    void f(int num,int n, vector<int>&ans){
        if(num>n) return;
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            num*=10; num+=i;
            f(num,n,ans);
            num/=10;
        } 
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int j=1;j<=9;j++) f(j,n,ans);
        return ans;
    }
};
