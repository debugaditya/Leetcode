class Solution {
public:
    unordered_map<int,TreeNode*>mp;
    TreeNode* s; TreeNode* r;
    void traversal(TreeNode* root,int start, int dest){
        if(!root) return;
        if(root->left) mp[root->left->val]=root;
        if(root->right) mp[root->right->val]=root;
        if(root->val==start) s=root;
        if(root->val==dest) r=root;
        traversal(root->left,start,dest); traversal(root->right,start,dest);
    }
    string level(TreeNode* par, int value){
        if(!par) return "";
        if(par->val==value) return "U";
        string left=level(par->left,value);
        string right=level(par->right,value);
        if(left==""&&right=="") return "";
        else if(left=="") return right+'U';
        return left+'U';
    }
    void path(TreeNode* par, int value,string &s,string &ans){
        if(!par) return;
        if(ans.size()>0) return;
        if(par->val==value){ans=s; return;}
        s+='L'; path(par->left,value,s,ans); s.pop_back();
        s+='R'; path(par->right,value,s,ans); s.pop_back();
    }
    string getDirections(TreeNode* root, int start, int dest) {
        mp[root->val]=root; unordered_set<TreeNode*>st;
        traversal(root,start,dest);
        TreeNode* par=s;
        while(par!=root){
            st.insert(par);
            int x=par->val;
            if (mp.find(x) != mp.end()) par=mp[x];
            else break;
        } 
        par=r;
        while(par!=root){
            if(st.count(par)) break;
            int x=par->val;
            if (mp.find(x) != mp.end()) par=mp[x];
            else break;
        }
        string ans=level(par,start); ans.erase(ans.begin());
        string s1,a; 
        path(par,dest,s1,a);
        ans+=a;
        return ans;
    }
};

