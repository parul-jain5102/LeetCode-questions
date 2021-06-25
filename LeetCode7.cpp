class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
        ListNode *curr=head;
        int sum=0;
        while(curr!=NULL)
        {
            sum=sum+curr->val;
            if(sum==0)
            {
                head=curr->next;
                mp.clear();
                curr=curr->next;
                continue;
            }
            if(mp.find(sum)!=mp.end())
            {
                ListNode *alpha=mp[sum];
                ListNode *left=alpha->next;
                int deleteSum=sum;
                while(left!=curr)
                {
                    deleteSum=deleteSum+left->val;
                    mp.erase(deleteSum);
                    left=left->next;
                }
                alpha->next=curr->next;
                curr=curr->next;
            }
            else
            {
                mp[sum]=curr;
                curr=curr->next;
            }
        }
        return head;
        
        
    }
};
