Determine the vertical order traversal and add the first root with new horizontal distance in the top view.
Vertical order is printing nodes according to their horizontal distance from the root. So horizontal distance of root = 0, and for any child:
Horizontal distance of left child = Horizontal distance of parent - 1
Horizontal distance of right child = Horizontal distance of parent + 1
So, maintain a map of horizontal distance and keep pushing the nodes having that value as horizontal distance.

vector<int> topView(Node *root)
    {
        map<int, int> hd;
        hd[root->data] = 0;
        queue<Node *> q;
        q.push(root);
        map<int,int>mp;
        while (!q.empty())
        {
            Node *val = q.front();
            q.pop();
            if(mp.count(hd[val->data])==0)
                mp[hd[val->data]]=val->data;
            if (val->left)
                hd[val->left->data] = hd[val->data] - 1, q.push(val->left);
            if (val->right)
                hd[val->right->data] = hd[val->data] + 1, q.push(val->right);
        }
        vector<int>answer;
        for(auto i = mp.begin(); i!=mp.end();i++)
            answer.push_back(i->second);
        return answer;
    }
Similarly for the bottom view, we need to add the last node with horizontal distance in the bottom view.

vector <int> bottomView(Node *root)
{
    vector<int>answer;
    if(root==NULL)
        return answer;
    int hd = 0;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, hd));
    map<int,int>mp;
    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        Node *val = p.first;
        hd = p.second;
        q.pop();
        mp[hd] = val->data;
        if (val->left)
            q.push(make_pair(val->left, hd-1));
        if (val->right)
            q.push(make_pair(val->right, hd+1));
    }
    for(auto i = mp.begin(); i!=mp.end();i++)
        answer.push_back(i->second);
    return answer;
}
