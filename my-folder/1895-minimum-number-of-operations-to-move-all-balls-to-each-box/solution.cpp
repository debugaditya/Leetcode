class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>v;
        int n=boxes.size();
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<n;j++){
                if(boxes[j]=='1') ans+=abs(i-j);
            }
            v.push_back(ans);
        }
        return v;
    }
};
