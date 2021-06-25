class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         if(head== NULL || head->next==NULL)
                return head;
        ListNode *oddStart=NULL, *evenStart=NULL;
        ListNode *oddEnd=NULL,*evenEnd = NULL;
        int cnt=1;
        while(head)
        {
            if((cnt&1))
            {
                if(oddEnd)
                {
                    oddEnd->next=head;
                    oddEnd=head;
                    head=head->next;
                    oddEnd->next=NULL;
                }    
                else
                {
                    oddStart=head;
                    oddEnd=head;
                    head=head->next;
                    oddEnd->next=NULL;
                }
                
            }
            else
            {
                if(evenEnd)
                {
                    evenEnd->next=head;
                    evenEnd=head;
                    head=head->next;
                    evenEnd->next=NULL;
                }    
                else
                {
                    evenStart=head;
                    evenEnd=head;
                    head=head->next;
                    evenEnd->next=NULL;
                }
                
            }
            cnt++;
        }
        oddEnd->next=evenStart;
        return oddStart;

        
    }
};
