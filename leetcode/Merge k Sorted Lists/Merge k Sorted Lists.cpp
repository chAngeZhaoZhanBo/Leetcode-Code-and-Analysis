class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;

        auto cmp=[](ListNode* a,ListNode* b){return (a->val)>(b->val);};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        
        for(auto node:lists){
            if(node!=nullptr)
                q.push(node);
        }
        if(q.empty())
            return nullptr;

        ListNode* top=q.top();
        ListNode* root=new ListNode(0);
        ListNode* current=root;

        while(q.size()>1){
            current->next=top;
            q.pop();
            if(top->next!=nullptr){
                q.push(top->next);
            }
            top=q.top();
            current=current->next;
        }
        current->next=q.top();
        return root->next;
    }
};
