class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans=0; unordered_set<int>st(nums.begin(),nums.end());
        while(head->next){
            if(st.count(head->val)&&!st.count(head->next->val)) ans++;
            head=head->next;
        }
        if(st.count(head->val)) ans++;
        return ans;
    }
};
