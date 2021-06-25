bool check(ListNode* &left, ListNode *right)
{
    	if(right==NULL)
       		 return true;
	if(check(left,right->next) && (right->val==left->val))
	{
		left=left->next;
		return true;
	}
	return false;
	
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
          ListNode *left=head;
    ListNode *right=head;
    bool ans = check(left,right);
    return ans;

    }
};
