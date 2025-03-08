class Solution {
public:
    void inorder(TreeNode* root,map<int,TreeNode*>&mp,vector<int>&v){
        if(!root) return;
        inorder(root->left,mp,v);
        v.push_back(root->val);
        mp[root->val]=root;
        inorder(root->right,mp,v);
        return;
    }
    void recoverTree(TreeNode* root) {
        map<int,TreeNode*>mp;
        vector<int>v;
        inorder(root,mp,v);
        vector<int>duplicate(v.begin(),v.end());
        sort(duplicate.begin(),duplicate.end());
        int a;
        int b;
        bool d= false;
        for(int i=0;i<v.size();i++){
            if(duplicate[i]!=v[i]&&!d){
                d=true;
                a=v[i];
            }
            else if(duplicate[i]!=v[i]&&d){
                b=v[i];
                break;
            }
        }
        swap(mp[a]->val,mp[b]->val);
        return;
    }
};
