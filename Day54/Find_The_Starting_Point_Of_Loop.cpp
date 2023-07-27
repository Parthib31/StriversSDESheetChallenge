Node *firstNode(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) break;
    }
    if (fast==NULL || fast->next==NULL) return NULL;
    fast=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}