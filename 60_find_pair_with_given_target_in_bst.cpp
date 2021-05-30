/*void inorder(Node* root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }*/
    
    int isPairPresent(struct Node *root, int target)
    {
        /*vector<int>ans;
        inorder(root, ans);
        int l=0, r=ans.size()-1;
        while(l<r)
        {
            int sum = ans[l]+ans[r];
            if(sum==target)
                return 1;
            else if(sum<target)
                l++;
            else
                r--;
        }
        return 0;*/
        stack<Node*>s1;
        stack<Node*>s2;
        Node* tmp1 = root, *tmp2 = root;
        int val1 =0, val2=0;
        bool d1=0,d2=0;
        while(1)
        {
            while(!d1)
            {
                if(tmp1)
                {   
                    s1.push(tmp1);
                    tmp1 = tmp1->left;
                }
                else
                {
                    if(s1.size())
                    {
                        tmp1 = s1.top();
                        s1.pop();
                        val1 = tmp1->data;
                        tmp1 = tmp1->right;
                    }
                    d1=1;
                }
            }
            
            while(!d2)
            {
                if(tmp2)
                {   
                    s2.push(tmp2);
                    tmp2 = tmp2->right;
                }
                else
                {
                    if(s2.size())
                    {
                        tmp2 = s2.top();
                        s2.pop();
                        val2 = tmp2->data;
                        tmp2 = tmp2->left;
                    }
                    d2=1;
                }
            }
            
            if(val1!=val2&&(val1+val2)==target)
                return 1;
            
            else if((val1+val2)<target)
                d1=0;
            
            else if((val1+val2)>target)
                d2=0;
                
            if(val1>=val2)
                return false; // inorder traversals crossed each other
        }
    }
