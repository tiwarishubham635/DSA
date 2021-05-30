vector<int> findSpiral(Node *root)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
        
    stack<Node*>s1;
    stack<Node*>s2;
    
    s1.push(root);
    while((!s1.empty())||(!s2.empty()))
    {
        while(!s1.empty())
        {
            Node* val = s1.top();
            s1.pop();
            if(val->right!=NULL)
                s2.push(val->right);
            if(val->left!=NULL)
                s2.push(val->left);
            ans.push_back(val->data);
        }
        
        while(!s2.empty())
        {
            Node* val = s2.top();
            s2.pop();
            if(val->left!=NULL)
                s1.push(val->left);
            if(val->right!=NULL)
                s1.push(val->right);
            ans.push_back(val->data);
        }
    }
    
    return ans;
}
