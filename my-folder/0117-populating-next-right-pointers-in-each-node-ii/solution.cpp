class Solution {
public:
    Node* helper(Node* root){
        if(!root) return NULL;
        if(root->left) return root->left;
        if(root->right) return root->right;
        return helper(root->next);
    } 
    void f(Node* root){
        if(!root) return;
        if(root->right){
            if(root->left) root->left->next=root->right;
            root->right->next=helper(root->next);
        }
        else if(root->left) root->left->next=helper(root->next);
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q; root->next=NULL;
        q.push(root);
        while(!q.empty()){
            f(q.front());
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        return root;
    }
};
