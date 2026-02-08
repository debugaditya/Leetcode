class RideSharingSystem {
public:
    unordered_map<int,int>mp;
    queue<int>d,r;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        r.push(riderId);
        mp[riderId]=1;
    }
    
    void addDriver(int driverId) {
        d.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(r.empty()||d.empty()) return {-1,-1};
        vector<int>v={d.front(),r.front()};
        mp[r.front()]=0;
        r.pop(); d.pop();
        return v;
    }
    
    void cancelRider(int riderId) {
        if(mp[riderId]!=1||r.empty()) return;
        int n=r.size();
        while(n--){
            if(r.front()==riderId) r.pop();
            else{
                r.push(r.front());
                r.pop();
            }
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
