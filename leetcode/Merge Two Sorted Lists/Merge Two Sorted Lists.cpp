class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root,* now,* prev;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val<l2->val){
            root=l1;
            prev=l1;
        }
        else{
            root=l2;
            prev=l2;
        }
        while(l1&&l2){
            if(l1->val<l2->val){
                now=l1;
                l1=l1->next;
            }
            else{
                now=l2;
                l2=l2->next;
            }
            prev->next=now;
            prev=now;
        }
        if(l1){
            now->next=l1;
        }
        else{
            now->next=l2;
        }
        return root;
    }
};
