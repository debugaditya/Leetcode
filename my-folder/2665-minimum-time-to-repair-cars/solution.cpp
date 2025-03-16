class Solution {
public:
    bool f(long long time,vector<int>& ranks, int cars){
        int sum=0;
        for(auto it:ranks){
            sum+=sqrt(time/it);
            if(sum>=cars) return true;
        }
        return sum>=cars;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        long long l=0;
        int mini=*min_element(ranks.begin(),ranks.end());
        long long r=cars*cars*mini;
        while(l<=r){
            long long mid=(l+r)/2;
            if(f(mid,ranks,cars)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
