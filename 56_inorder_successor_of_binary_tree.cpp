Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(x==NULL)
            return NULL;
        Node* tmp=NULL;
        if(x->right)
        {
            tmp = x->right;
            Node* prev = NULL;
            while(tmp)
            {
                prev = tmp;
                tmp = tmp->left;
            }
            tmp = prev;
        }
        else
        {
            while(root!=x)
            {
                if(root->data > x->data)
                {
                    tmp = root;
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return tmp;
    }
Inorder Successor - If the root has the right child, then return the left-most value(smallest value in the right subtree) of the right subtree, else start from the root and reach the target node, the node at which the last left was taken, is the inorder successor.
Similarly, Inorder Predecessor - If the root has the left child, then return the right-most value(largest value in the right subtree) of the left subtree, else start from the root and reach the target node, the node at which the last right was taken, is the inorder predecessor.
