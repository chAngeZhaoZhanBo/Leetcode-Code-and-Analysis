class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* left=head,*right=head;
        for(int i=0;i<n;++i){
            right=right->next;
        }
        while(right){
            pre=pre->next;
            left=left->next;
            right=right->next;
        }
        pre->next=left->next;
        return dummy->next;
    }
};
