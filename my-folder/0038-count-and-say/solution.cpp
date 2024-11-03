class Solution {
public:
	string countAndSay(int n) {
        if(n==1){
            return "1";
        }
		int z=2;
		string ans="1";
		while(n>=z) {
            string u=ans;
            ans="";
			int cnt=1;
			int t=0;
			for(int i=0; i<u.size()-1; i++) {
				if(u[i]==u[i+1]) {
					cnt++;
				}
				else {
					ans+=to_string(cnt);
					ans+=u[i];
                    cnt=1;
				}
			}
            ans+=to_string(cnt);
            ans+=u[u.size()-1];
            z++;
		}
        return ans;

	}
};
