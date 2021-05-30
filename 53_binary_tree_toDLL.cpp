void helper(Node* root, Node** prev, Node** head)
    {
        if(root==NULL)
            return;
        helper(root->left, prev, head);
        if((*prev)==NULL)
            (*prev) = root, (*head) = root;
        else
        {
            root->left = *prev;
            (*prev)->right = root;
            (*prev) = root;
        }
        helper(root->right, prev, head);
    }

    Node *bToDLL(Node *root)
    {
        Node* prev = NULL;
        Node* head = NULL;
        helper(root, &prev, &head);
        return head;
    }
