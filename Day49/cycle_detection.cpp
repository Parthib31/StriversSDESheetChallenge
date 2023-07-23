class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast,*last;
        fast=last=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            last=last->next;
            if(fast==last) 
                return true;
        }

        return false;
    }
};