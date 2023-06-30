class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* forward=head->next;
        head->next=NULL;

        ListNode* reverse_rest=reverseList(forward);
        forward->next=head;
        return reverse_rest;
    }
};