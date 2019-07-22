/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,result=0,x,y;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        ListNode* now;
        while(l1!=nullptr||l2!=nullptr){
            x=(l1)?l1->val:0;
            y=(l2)?l2->val:0;
            result=x+y+carry;
            if(result>=10){
                carry=1;
                result-=10;
            }
            else
                carry=0;
            now=new ListNode(result);
            prev->next=now;
            prev=now;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            
        }
        if(carry){
            now=new ListNode(1);
            prev->next=now;
        }
        return dummy->next;
    }
};
