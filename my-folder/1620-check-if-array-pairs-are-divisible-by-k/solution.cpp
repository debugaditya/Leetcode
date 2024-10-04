class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%k>0){
                arr[i]=arr[i]%k;
            }
            else{
                arr[i]=(arr[i]%k) +k;
            }
            if(arr[i]==k){
                cnt++;
            }
            
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr.size()-1;
        if(cnt%2!=0){
            return false;
        }

        while(l<r){
            if(arr[r]==k){
                r--;
            }
            else if(arr[l]+arr[r]==k){
                r--;
                l++;
            }
            else{
                return false;
            }
        }
        return true;

        
    }
};
