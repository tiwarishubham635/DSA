int height(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(Node *root)
{
    if(root==NULL)
        return true;
    int n1 = height(root->left);
    int n2 = height(root->right);
    if(abs(n1-n2)<=1&&isBalanced(root->left)&&isBalanced(root->right))
        return true;
    else
        return false;
}
