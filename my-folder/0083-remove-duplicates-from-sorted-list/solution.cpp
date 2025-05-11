class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
            if(curr->val==prev->val){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
