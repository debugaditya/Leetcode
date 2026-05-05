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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tail=head; int size=1;
        while(tail->next){
            size++;
            tail=tail->next;
        }
        k%=size; if(k==0) return head;
        int a=size-k-1; ListNode* b=head;
        while(a--) b=b->next;
        ListNode* c=b->next;
        tail->next=head; b->next=nullptr;
        return c;
    }
};
