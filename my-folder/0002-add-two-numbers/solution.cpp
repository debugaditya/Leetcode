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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0); ListNode* head=ans;
        int carry=0;
        while(l1&&l2){
            int sum=l1->val+l2->val+carry;
            ListNode*temp =new ListNode(sum%10);
            head->next=temp;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
            head=head->next;
        }
        while(l1){
            int sum=l1->val+carry;
            ListNode*temp =new ListNode(sum%10);
            head->next=temp;
            carry=sum/10;
            l1=l1->next;
            head=head->next;
        }
        while(l2){
            int sum=l2->val+carry;
            ListNode*temp =new ListNode(sum%10);
            head->next=temp;
            carry=sum/10;
            l2=l2->next;
            head=head->next;
        }
        if(carry>0) {
            ListNode*temp =new ListNode(carry);
            head->next=temp;
        }
        return ans->next;
    }
};
