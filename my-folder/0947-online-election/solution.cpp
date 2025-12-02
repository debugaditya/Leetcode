class TopVotedCandidate {
public:
    unordered_map<int,int>freq; int maxi=0,lead; vector<pair<int,int>>v;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for(int i=0;i<times.size();i++){
            freq[persons[i]]++;
            if(maxi<=freq[persons[i]]) {lead=persons[i]; maxi=freq[persons[i]]; v.push_back({times[i],lead});}
        }
    }
    int q(int t) {
        int idx=upper_bound(v.begin(),v.end(),make_pair(t,INT_MAX))-v.begin(); 
        return v[idx-1].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
