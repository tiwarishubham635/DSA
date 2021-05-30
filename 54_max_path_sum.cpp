int maxPath(Node* root, int &ans)
{ 
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    int l = maxPath(root->left, ans);
    int r = maxPath(root->right, ans);
    
    if(root->left&&root->right)
    {
        ans = max(ans, l+r+(root->data));
        return max(l,r)+(root->data);
    }
    return ((root->left)?l+(root->data):r+(root->data));
}

int maxPathSum(Node* root)
{
    int ans = INT_MIN;
    int val = maxPath(root, ans);
    if(ans==INT_MIN)
        return val;
    return ans;
}
