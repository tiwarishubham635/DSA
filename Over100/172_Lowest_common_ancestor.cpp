TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
            return root;
        
        if(root->val == p->val or root->val == q->val)
            return root;
            
        TreeNode* val_in_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* val_in_right = lowestCommonAncestor(root->right, p, q);
        
        if(val_in_left&&val_in_right)
            return root;
        
        return (val_in_left?val_in_left:val_in_right);
    }
