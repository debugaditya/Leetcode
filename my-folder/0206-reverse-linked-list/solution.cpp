class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node=NULL;
        ListNode* temp;
        while(head){
            temp=head->next;
            head->next=node;
            node=head;
            head=temp;
        }
        return node;
    }
};
