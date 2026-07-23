class Solution {
public:
    int f(int n){
        return pow(2,(int)log2(n)+1);
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        return f(n);
    }
};
