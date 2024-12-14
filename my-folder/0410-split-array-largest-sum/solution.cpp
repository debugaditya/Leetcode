class Solution {
public:
int f(vector<int>arr,int maxi){
    int sum=0;
    int t=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxi){
            t++;
            sum=arr[i];
        }
    }
    return t+1;
}
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
    int r= accumulate(nums.begin(),nums.end(),0);
    while(l<=r){
        int mid=(l+r)/2;
        if(f(nums,mid)>k){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return l;
        
    }
};
