class Solution {
public:
    vector<string> validateCoupons(vector<string>& c, vector<string>& b, vector<bool>& is){
        for(int i=0;i<is.size();i++){
            if(!is[i]||c[i].size()==0){
                c.erase(c.begin()+i);
                b.erase(b.begin()+i);
                is.erase(is.begin()+i);
                i--;
            }
        }
        for(int i=0;i<c.size();i++){
            for(auto it1:c[i]){
                if(!isdigit(it1)&&!isalpha(it1)&&it1!='_'){
                    c.erase(c.begin()+i);
                    b.erase(b.begin()+i);
                    i--;
                    break;
                }
            }
        }
        vector<string>elec,gro,phar,rest;
        for(int i=0;i<c.size();i++){
            if(b[i]=="electronics") elec.push_back(c[i]);
            if(b[i]=="grocery") gro.push_back(c[i]);
            if(b[i]=="pharmacy") phar.push_back(c[i]);
            if(b[i]=="restaurant") rest.push_back(c[i]);
        }
        sort(elec.begin(),elec.end());
        sort(gro.begin(),gro.end());
        sort(phar.begin(),phar.end());
        sort(rest.begin(),rest.end());
        for(auto it:gro) elec.push_back(it);
        for(auto it:phar) elec.push_back(it);
        for(auto it:rest) elec.push_back(it);
        return elec;
    }
};
