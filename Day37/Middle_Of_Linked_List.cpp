Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head;
    Node *fast=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        
    }
    return slow;
}