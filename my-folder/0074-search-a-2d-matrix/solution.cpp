class Solution {
public:
    int f(vector<vector<int>>v,int t){
        int l=0;
        int r=v.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid][0]==t) return mid;
            else if(v[mid][0]>t) r=mid-1;
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
    bool g(vector<int>v,int target){
        int l=0;
        int r=v.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid]==target) return true;
            else if(v[mid]>target) r=mid-1;
            else{
                l=mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index=f(matrix,target);
        if(index==-1) return false;
        bool d=g(matrix[index],target);
        return d;
    }
};
