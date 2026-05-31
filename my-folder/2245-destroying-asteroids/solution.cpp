class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long m=mass;
        for(auto it:a){
            if(m<it) return false;
            m+=it;
        }
        return true;
    }
};
