class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dup=head;
        while(head->next){
            head->next=new ListNode(gcd(head->val,head->next->val),head->next);
            head=head->next->next;
        }
        return dup;
    }
};
