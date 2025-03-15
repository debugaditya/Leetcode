class Solution {
public:
    void f(map<int,int>mp,set<int>st,int index,int number,int &ans){
        if(index==3){
            if(number>=100&&number%2==0) ans++;
            return;
        }
        for(auto it:st){
            map<int,int>mp1=mp;
            set<int>st1=st;
            mp1[it]--;
            if(mp1[it]==0) st1.erase(it);
            int number1=10*number+it;
            f(mp1,st1,index+1,number1,ans);
        }
        return;
    }
    int totalNumbers(vector<int>& d) {
        map<int,int>mp;
        set<int>st;
        int even=0;
        for(auto it:d){
            mp[it]++;
            st.insert(it);
        }
        for(auto it:st) if (it%2==0) even++;
        int ans=0;
        f(mp,st,0,0,ans);
        return ans;
    }
};
