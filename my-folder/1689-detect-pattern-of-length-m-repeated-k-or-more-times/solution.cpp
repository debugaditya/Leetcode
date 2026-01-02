class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int cnt=0;
        for(int i=m;i<arr.size();i++){
            if(arr[i]==arr[i-m]) cnt++;
            else cnt=0;
            if(cnt==m*(k-1)) return true;
        }
        return false;
    }
};
