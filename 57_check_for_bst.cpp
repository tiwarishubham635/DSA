bool isBST(Node* root) 
    {
        if(root==NULL)
            return true;
        if(root->left==NULL&&root->right==NULL)
            return true;
        if(isBST(root->left)&&isBST(root->right))
        {
            Node* tmp;
            if(root->left)
            {
                tmp = root->left;
                while(tmp->right)
                    tmp = tmp->right;
                if(tmp->data >= root->data)
                    return false;
            }
            
            if(root->right)
            {
                tmp = root->right;
                while(tmp->left)
                    tmp = tmp->left;
                if(tmp->data < root->data)
                    return false;
            }
            return true;
        }
        else
            return false;
    }
