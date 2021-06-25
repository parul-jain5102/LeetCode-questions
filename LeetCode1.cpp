class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *slow=head,*fast=head,*PrevOfSlow=NULL;
        while(n--)
                fast=fast->next;
        while(fast)
        {
            PrevOfSlow = slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(PrevOfSlow)
            PrevOfSlow->next=slow->next;
        else
        {
            head=head->next;
        }
        //slow->next=NULL;
        //delete slow;
        return head;

        
    }
};
