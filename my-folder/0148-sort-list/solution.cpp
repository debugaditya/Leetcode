class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* a=new ListNode(v[0]); ListNode* b=a;
        for(int i=1;i<v.size();i++){
            ListNode* temp=new ListNode(v[i]);
            b->next=temp;
            b=temp;
        }
        return a;
    }
};
