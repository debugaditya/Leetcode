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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=head->next->next; int first=-1,last=-1,i=0,mini=INT_MAX;
        while(next){
            if((curr->val<prev->val&&curr->val<next->val)||(curr->val>prev->val&&curr->val>next->val)){
                if(first==-1) first=i;
                if(last!=-1) mini=min(mini,i-last);
                last=i;
            }
            next=next->next; prev=prev->next; curr=curr->next; i++;
        }
        if(first==last) return {-1,-1};
        return {mini,last-first};
    }
};
