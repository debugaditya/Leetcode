class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>st; int ans=INT_MIN;
        ListNode* fast=head; ListNode* slow=head;
        while(fast){
            st.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow){
            ans=max(slow->val+st.back(),ans);
            slow=slow->next; st.pop_back();
        }
        return ans;
    }
};
