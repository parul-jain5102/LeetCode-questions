class Solution {
public:
    int index=0;
    map<int,int> mp;
    TreeNode* Tree(int start,int end,vector<int> &preorder)
    {
        if(start>end)
              return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        int pos=mp[preorder[index]];
        index++;
        root->left=Tree(start,pos-1,preorder);
        root->right=Tree(pos+1,end,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* Root=Tree(0,n-1,preorder);
        return Root;
    }
};
