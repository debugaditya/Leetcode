class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        priority_queue<pair<int,int>>pq; vector<int>a;
        for(auto it:nums){
            vector<int>temp; int power=1,ans=0,n=it;
            while(it>0){
                temp.push_back(it%2);
                it/=2;
            }
            for(int i=temp.size()-1;i>=0;i--){
                ans+=power*temp[i];
                power*=2; 
            }
            pq.push({ans,n});
        }
        while(!pq.empty()){a.push_back(pq.top().second); pq.pop();}
        reverse(a.begin(),a.end());
        return a;
    }
};
