class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* dummy=even;
        while(odd->next&&even->next){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=dummy;
        return head;
    }
};
