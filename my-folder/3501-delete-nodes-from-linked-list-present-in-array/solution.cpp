class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* dummy2=head;
        ListNode* dummy1=new ListNode(-1,dummy2);
        ListNode* ans=dummy1;
        while(dummy2){
            if(st.find(dummy2->val)!=st.end()){
                dummy1->next=dummy2->next;
                dummy2=dummy1->next;
            }
            else{
                dummy1=dummy2;
                dummy2=dummy2->next;
            }
        }
        return ans->next;
    }
};
