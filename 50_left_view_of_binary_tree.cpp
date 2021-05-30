void levelorder(Node* root, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> tmp;

    while (1)
    {
        Node *val = q.front();
        q.pop();
        if (val == NULL && q.empty())
            break;
        if (val == NULL && q.size())
        {
            ans.push_back(tmp);
            tmp.clear();
            q.push(NULL);
            continue;
        }
        tmp.push_back(val->data);
        if (val->left)
            q.push(val->left);
        if (val->right)
            q.push(val->right);
    }
    if (tmp.size())
        ans.push_back(tmp);
}

vector<int> leftView(Node *root)
{
    vector<vector<int>> ans;
    levelorder(root, ans);
    vector<int>tmp;
    for(int i=0;i<ans.size();i++)
        tmp.push_back(ans[i][0]);
    return tmp;
}
	Here, we need to store level order traversal level wise and print the first element of each level in the left view.
Similarly for the right view, print the last element of each level.
