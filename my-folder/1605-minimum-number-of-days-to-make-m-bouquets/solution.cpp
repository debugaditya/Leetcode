class Solution {
public:
int maxi(vector<int>arr){
	int t=INT_MIN;
	for(int j=0;j<arr.size();j++){
		t=max(t,arr[j]);
	}
	return t;
}
int f(vector<int> arr, int a,int k){
	int z=0;
	int cnt=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=a){
			z++;
		}
		else{
			cnt+=(z/k);
			z=0;
		}
	}
	cnt+=z/k;
	return cnt;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=maxi(bloomDay);
	    int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
		    vector<int>temp(bloomDay.begin(),bloomDay.end());
		    int q=f(temp,mid,k);
		    if(q>=m){
                ans=mid;
			    r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
        
    }
};
