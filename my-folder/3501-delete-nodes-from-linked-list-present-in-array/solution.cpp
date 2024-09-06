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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        
        ListNode* t = head;
        ListNode* p = nullptr;
        while (head != nullptr && mp.find(head->val) != mp.end()) {
            ListNode* dl = head;
            head = head->next;
            delete(dl);
        }
        
        t = head;  
        
        while (t != nullptr) {
            if (mp.find(t->val) != mp.end()) {
                ListNode* dl = t;
                if (p != nullptr) {
                    p->next = t->next;
                }
                t = t->next;
                delete(dl);
            } else {
                p = t;
                t = t->next;
            }
        }
        
        return head;
    }
};
