class Router {
public:
    unordered_map<int,vector<int>>mp; 
    int m;   
    struct T{
        int s;
        int d;
        int t;
        bool operator<(const T& other) const {
            if(s!=other.s) return s<other.s;
            if(d!=other.d) return d<other.d;
            return t<other.t;
        }
    };
    queue<T>q; set<T>st;
    Router(int memoryLimit) {
        m=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        T pkt;
        pkt.s=source;  pkt.d=destination; pkt.t=timestamp;
        if(st.count(pkt)) return false;
        if(q.size()==m){
            T old=q.front();
            st.erase(old); q.pop();
            mp[old.d].erase(mp[old.d].begin());
        }
        q.push(pkt); st.insert(pkt);
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0) return {};
        T pkt=q.front();
        q.pop(); st.erase(pkt);
        mp[pkt.d].erase(mp[pkt.d].begin());
        return {pkt.s,pkt.d,pkt.t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int>&v=mp[destination];
        if(v.size()==0) return 0;
        int idx1 = lower_bound(v.begin(), v.end(), startTime) - v.begin();
        int idx2 = upper_bound(v.begin(), v.end(), endTime) - v.begin();
        return idx2-idx1;
    }
};


