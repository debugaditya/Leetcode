class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>st;
        int cnt=0;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            if(st.find(A[i])!=st.end()) cnt++;
            if(st.find(B[i])!=st.end()) cnt++;
            if(A[i]==B[i]) cnt++;
            st.insert(A[i]);
            st.insert(B[i]);
            ans.push_back(cnt);
        }
        return ans;
    }
};
