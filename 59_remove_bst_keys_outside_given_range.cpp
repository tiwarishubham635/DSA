Node* removekeys(Node* root, int l, int r) 
    {
        if(root==NULL)
            return NULL;
            
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        if(root->data < l)
        {
            Node* ans = root->right;
            delete root;
            return ans;
        }
        
        if(root->data > r)
        {
            Node* ans = root->left;
            delete root;
            return ans;
        }
            
        return root;
    }
