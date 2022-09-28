class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slow=head, *fast=head;
        while(n!=0 && fast!=NULL)
        {
            fast=fast->next;
            if(!fast)
                return head->next;
            n--;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};