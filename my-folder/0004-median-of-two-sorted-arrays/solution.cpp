class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int left=(n1+n2)/2;
        int l=0;
        int r=n1;
        while(l<=r){
            int mid=(l+r)/2;
            int l1=mid-1;
            int l2=left-mid-1;
            int r1=mid;
            int r2=left-mid;
            int nl1=INT_MIN;
            int nl2=INT_MIN;
            int nr1=INT_MAX;
            int nr2=INT_MAX;
            if(l1!=-1) nl1=nums1[l1]; 
            if(l2!=-1) nl2=nums2[l2];
            if(r1!=n1) nr1=nums1[r1];
            if(r2!=n2) nr2=nums2[r2];
            if(max(nl1,nl2)<=min(nr1,nr2)){
                if((n1+n2)%2==1) return min(nr1,nr2);
                return (max(nl1,nl2)+min(nr1,nr2))/2.0;
            }
            else if(nl1==max(nl1,nl2)) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};
