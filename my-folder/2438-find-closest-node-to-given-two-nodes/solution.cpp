class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2) return node1;
        unordered_set<int>st1={node1}; unordered_set<int>st2={node2}; unordered_set<int>st;
        vector<int>v1={node1}; vector<int>v2={node2};
        while(edges[v1.back()]!=-1&&!st1.count(edges[v1.back()])){
            st1.insert(edges[v1.back()]);
            v1.push_back(edges[v1.back()]);
        }
        while(edges[v2.back()]!=-1&&!st2.count(edges[v2.back()])){
            st2.insert(edges[v2.back()]);
            v2.push_back(edges[v2.back()]);
        }
        for(int i=0;i<max(v1.size(),v2.size());i++){
            if(i<v1.size()&&st.count(v1[i])&&i<v2.size()&&st.count(v2[i])) return min(v1[i],v2[i]);
            if(i<v1.size()&&st.count(v1[i])) return v1[i];
            if(i<v2.size()&&st.count(v2[i])) return v2[i];
            if(i<v1.size()&&i<v2.size()&&v1[i]==v2[i]&&v1[i]) return v1[i];
            if(i<v2.size()) st.insert(v2[i]);
            if(i<v1.size()) st.insert(v1[i]);
        }
        return -1;
    }
};
