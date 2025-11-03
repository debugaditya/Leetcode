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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0,i=0; ListNode* a=head; ListNode* b=head; ListNode* prev=nullptr; 
        while(a){
            size++;
            a=a->next;
        }
        while(i<size-n){
            i++; prev=b;
            b=b->next;
        }
        if(prev) {prev->next=b->next; b->next=nullptr;}
        else return b->next;
        return head;
    }
};
