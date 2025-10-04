class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a=head;
        ListNode* b=head; ListNode* c=head; int i=1,j=1;
        while(c->next){
            if(i<k) a=a->next;
            c=c->next;
            i++;
        }
        while(j<i+1-k){
            b=b->next;
            j++;
        }
        swap(a->val,b->val);
        return head;
    }
};
