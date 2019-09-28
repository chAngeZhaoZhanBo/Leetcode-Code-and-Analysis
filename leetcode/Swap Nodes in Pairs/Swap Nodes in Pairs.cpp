//recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* next=head->next,*tmp=swapPairs(next->next);
        next->next=head;
        head->next=tmp;
        return next;
    }
};

//iteration
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* left=head,*right=head->next,*pre=dummy;
        while(left!=nullptr&&left->next!=nullptr){
            right=left->next;
            pre->next=right;
            left->next=right->next;
            right->next=left;
            pre=left;
            left=pre->next;
        }
        return dummy->next;
    }
};
