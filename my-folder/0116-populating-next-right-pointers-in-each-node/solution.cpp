class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<pair<int,Node*>>q; q.push({1,root}); unordered_map<int,Node*>mp;
        while(!q.empty()){
            if(mp.count(q.front().first)) mp[q.front().first]->next=q.front().second;
            mp[q.front().first]=q.front().second;
            if(q.front().second->left) {q.push({q.front().first+1,q.front().second->left}); q.push({q.front().first+1,q.front().second->right});}
            q.pop();
        }
        return root;
    }
};
