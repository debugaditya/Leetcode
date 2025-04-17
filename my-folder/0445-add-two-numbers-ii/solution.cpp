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
        vector<int> a, b;

        while (l1) {
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            b.push_back(l2->val);
            l2 = l2->next;
        }

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        ListNode* ans = nullptr;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--];
            if (j >= 0) sum += b[j--];

            ListNode* temp = new ListNode(sum % 10);
            temp->next = ans;
            ans = temp;
            carry = sum / 10;
        }

        return ans;
    }
};

