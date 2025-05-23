class Solution {
public:
    unordered_map<int,string>mp;
    void f(vector<int>& c, int &t,int &cost,string &temp,string &ans){
        if(cost>t) return;
        if(cost==t){
            if(temp.size()>ans.size()) ans=temp;
            else if(temp.size()==ans.size()) ans=max(ans,temp);
            return;
        }
        if(mp.count(cost)&&mp[cost].size()>=temp.size()) return;
        mp[cost]=temp;
        for(int i=8;i>=0;i--){
            temp+=i+1+'0';
            cost+=c[i];
            f(c,t,cost,temp,ans);
            temp.pop_back();
            cost-=c[i];
        }
        return;
    }
    string largestNumber(vector<int>& c, int t) {
        string ans=""; string temp=""; int cost=0;
        f(c,t,cost,temp,ans);
        if(ans.size()==0) return "0";
        return ans;
    }
};
