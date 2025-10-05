class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=1,maxi=0,mini=arr.size()-1; vector<int>mx(arr.size()),mn(arr.size()); 
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[mini]>arr[i]) mini=i;
            mn[i]=mini;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[maxi]<arr[i]) maxi=i;
            mx[i]=maxi;
        }
        for(int i=0;i<arr.size()-1;i++) if(arr[mx[i]]<=arr[mn[i+1]]) ans++;
        return ans;
    }
};
