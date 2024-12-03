class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<double> st;  
        for (int i = 0; i < arr.size(); i++) {
            if (st.find(2.0*arr[i])!=st.end()||st.find(static_cast<double>(arr[i])/2.0)!=st.end()) {
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};

