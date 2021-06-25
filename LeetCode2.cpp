class mycomp{
    public:
        bool operator()(ListNode *a, ListNode *b)
        {
            return b->val<a->val;
        }    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,mycomp> pq;
        for(auto x:lists)
        {
            if(x)
                pq.push(x);
        }
        ListNode *mergeListHead=NULL,*mergeListLast=NULL;
        while(!pq.empty())
        {
            ListNode *u = pq.top();
           // cout<<u->val<<"  ";
            pq.pop();
            if(u->next!=NULL)
                pq.push(u->next);
            if(mergeListHead==NULL)
            {
                mergeListHead=u;
                mergeListLast=u;
                mergeListLast->next=NULL;
            }
            else
            {
                mergeListLast->next=u;
                mergeListLast=u;
                mergeListLast->next=NULL;
            }
            
        }
        return mergeListHead;

        
    }
};
