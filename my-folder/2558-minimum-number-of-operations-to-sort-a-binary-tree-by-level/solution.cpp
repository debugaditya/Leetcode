class Solution {
public:
    void f(TreeNode* root,vector<vector<int>>&v,int i){
        if(root==nullptr) return;
        if(v.size()<=i) v.push_back(vector<int>());
        v[i].push_back(root->val);
        f(root->left,v,i+1);
        f(root->right,v,i+1);
        return;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>v;
        int i=0;
        f(root,v,i);
        int cnt=0;
        for(int j=0;j<v.size();j++){
            vector<int>d(v[j].begin(),v[j].end());
            sort(d.begin(),d.end());
            map<int,int>mp;
            for(int y=0;y<v[j].size();y++){
                mp[v[j][y]]=y;
            }
            for(int k=0;k<v[j].size();k++){
                if(v[j][k]!=d[k]){
                    swap(v[j][k],v[j][mp[d[k]]]);
                    swap(mp[v[j][k]],mp[v[j][mp[d[k]]]]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
