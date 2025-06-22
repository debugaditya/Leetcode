class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v; 
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<v.size();i++){
            if(i%k<k/2){
                if(2*k*(i/k)+k-1-i<v.size()) swap(v[i],v[2*k*(i/k)+k-1-i]);
                else break;
            }
        }
        ListNode* ans=new ListNode(v[0]);
        ListNode* temp=ans;
        for(int i=1;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }
        return ans;
    }
};
