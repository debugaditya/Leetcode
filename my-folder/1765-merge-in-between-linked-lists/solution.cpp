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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=1; ListNode* ans=list1;
        while(i<a) {list1=list1->next; i++;}
        ListNode* bo=list1->next;
        while(list2){
            list1->next=list2;
            list1=list1->next;
            list2=list2->next;
        }
        while(i<b+1) {bo=bo->next; i++;}
        list1->next=bo;
        return ans;
    }
};
