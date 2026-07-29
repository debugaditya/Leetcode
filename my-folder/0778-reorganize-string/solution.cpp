class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        int maxi=0;
        int n=s.length();
        
        for(char c:s){
            hash[c-'a']++;
            maxi=max(maxi,hash[c-'a']);
        }
        if(maxi>ceil(s.length()/2.0)) return "";
        vector<pair<int,char>>pr;
        for(int i=0;i<26;i++){
            pr.push_back({hash[i],i+'a'});
        }
        sort(pr.begin(),pr.end());
        string ans(s.length(),'?');
        int ptr=0;
        for(int i=pr.size()-1;i>=0;i--){
            int f=pr[i].first;
            char ch=pr[i].second;
            if(f==0) break;
            while(f>0){
                ans[ptr]=ch;
                f--;
                int cnt=1;
                if(f==0) while(cnt<s.size()&&ans[ptr]!='?') {ptr++; ptr%=s.length(); cnt++;}
                else{
                    if(ptr<s.size()-1) {ptr+=2; ptr%=s.length();}
                    else ptr=0;
                    while(cnt<s.size()&&ans[ptr]!='?') {ptr++; ptr%=s.length(); cnt++;}
                }
            }
        }
        return ans;
        
    }
};
