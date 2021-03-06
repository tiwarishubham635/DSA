void inorder(TreeNode* root, vector<int>&ans) {
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        /*inorder(root, ans);
        return ans;*/
        
        /*
        ITERATIVE STACK
        stack<TreeNode*>s;
        
        while(root or !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;*/
        
        // ITERATIVE MORRIS METHOD
        while(root)
        {
            while(root->left)
            {
                TreeNode* last = root->left, *left_child = last;
                while(last->right)
                    last = last->right;
                last->right = root;
                root->left = NULL;
                root = left_child;
            }
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }

vector<int> inOrder(Node* root)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    Node* tmp = root;
    stack<Node*>s;
    while(tmp!=NULL||!s.empty())
    {
        while(tmp!=NULL)
        {
            s.push(tmp);
            tmp = tmp->left;
        }

        Node* val = s.top();
        s.pop();
        ans.push_back(val->data);
        tmp = val->right;
    }
}
vector<int> preOrder(Node* root)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node* val = s.top();
        ans.push_back(val->data);
        s.pop();
        if(val->right)
            s.push(val->right);
        if(val->left)
            s.push(val->left);
    }
    return ans;
}
vector<int> postOrder(Node* root) 
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node* val = s1.top();
        s1.pop();
        s2.push(val);
        if(val->left)
            s1.push(val->left);
        if(val->right)
            s1.push(val->right);
    }
    while(!s2.empty())
    {
        Node* val = s2.top();
        ans.push_back(val->data);
        s2.pop();
    }
    return ans;
}
