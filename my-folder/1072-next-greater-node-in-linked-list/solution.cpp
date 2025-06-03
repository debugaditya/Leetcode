/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v; stack<int>st;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int>ans(v.size(),0);
        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=v[i]) st.pop();
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top();
            st.push(v[i]); 
        } 
        return ans;
    }
};
