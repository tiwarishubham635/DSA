void printLeftBoundary(Node* root, vector<int>&ans)
    {
        if(root)
        {
            if(root->left)
            {
                ans.push_back(root->data);
                printLeftBoundary(root->left, ans);
            }
            else if(root->right)
            {
                ans.push_back(root->data);
                printLeftBoundary(root->right, ans);
            }
        }
    }
    
    void printRightBoundary(Node* root, vector<int>&ans)
    {
        if(root)
        {
            if(root->right)
            {
                printRightBoundary(root->right, ans);
                ans.push_back(root->data);
            }
            
            else if(root->left)
            {
                printRightBoundary(root->left, ans);
                ans.push_back(root->data); 
            }
        }
    }
    
    void printLeafNodes(Node* root, vector<int>&ans)
    {
        if(root)
        {
            printLeafNodes(root->left, ans);
            if(root->left==NULL&&root->right==NULL)
                ans.push_back(root->data);
            printLeafNodes(root->right, ans);
        }
    }
    
    vector <int> printBoundary(Node *root)
    {
        vector<int>ans;
        ans.push_back(root->data);
        printLeftBoundary(root->left, ans);
        printLeafNodes(root->left, ans);
        printLeafNodes(root->right, ans);
        printRightBoundary(root->right, ans);
        return ans;
    }
