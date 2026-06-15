class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode* fast=head; ListNode* slow=head; 
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(!slow->next) {head->next=nullptr; return head;}
        slow->val=slow->next->val;
        slow->next=slow->next->next;
        return head;
    }
};
