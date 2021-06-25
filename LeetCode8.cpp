class Solution {
public:
    int cnt=0;
    void help(TreeNode *root,int maxsofar)
    {
        if(root==NULL)
             return;
        if(root->val>=maxsofar)
        {
            cnt++;
            maxsofar=root->val;
        }
        help(root->left,maxsofar);
        help(root->right,maxsofar);
       
        
    }
    int goodNodes(TreeNode* root) {
        help(root,-10000000);
         return cnt;
        
    }
};
