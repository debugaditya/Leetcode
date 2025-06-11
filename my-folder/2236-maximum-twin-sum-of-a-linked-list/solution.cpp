class Solution {
public:
    int pairSum(ListNode* head) {
        int i=0,n=0,ans=INT_MIN;
        ListNode* temp=head;
        while(temp){
            n++; temp=temp->next;
        }
        vector<int>v(n/2);
        while(head){
            if(i<n/2) v[i]=head->val;
            else ans=max(ans,v[n-i-1]+head->val);
            head=head->next;
            i++;
        }
        return ans;
    }
};
