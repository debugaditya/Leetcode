class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>pre(arr.size()); pre[0]=0;
        for(int i=1;i<arr.size();i++) pre[i]=arr[i-1]+pre[i-1];
        int l=0,r=arr.back(),mini=INT_MAX;
        while(l<r){
            int mid1=(l+r)/2,mid2=mid1+1,diff1,diff2;
            int idx1=upper_bound(arr.begin(),arr.end(),mid1)-arr.begin(),idx2=upper_bound(arr.begin(),arr.end(),mid2)-arr.begin();
            if(idx1==arr.size()) diff1=abs(target-pre.back()-arr.back());
            else diff1=abs(pre[idx1]+(int)(arr.size()-idx1)*mid1-target);
            if(idx2==arr.size()) diff2=abs(target-pre.back()-arr.back());
            else diff2=abs(pre[idx2]+(int)(arr.size()-idx2)*mid2-target);
            if(diff1>diff2) l=mid2; else r=mid1;
        } 
        return r;
    }
};
