int diameter(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    return max(1+height(root->left)+height(root->right),max(d1,d2));
}
