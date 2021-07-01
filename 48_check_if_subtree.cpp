vector<Node*> nodes;
    int getDepth(Node* r, int d) 
    {
        if (!r)
            return -1;

        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

        // Check if depth equals required value
        // Require depth is -1 for tree t (only return the depth, no push)
        if (depth == d)
        {
            //if(d!=-1)
            //    cout<<r->data<<" "<<d<<endl;
            nodes.push_back(r);
        }
        return depth;
    }

    bool identical(Node* a, Node* b) 
    {
        if (!a && !b) 
            return true;
        if (!a || !b || a->data != b->data) 
            return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
    }
    
    bool isSubTree(Node* t, Node* s) 
    {
        if (!s && !t) 
            return true;
        if (!s || !t) 
            return false;

        int dep_s = getDepth(s, -1);
        getDepth(t, dep_s);

        for (Node* n: nodes)
        {
            if (identical(n, s))
                return true;
        }

        return false;
    }

Approach-1:
bool areIdentical(node * root1, node *root2) 
{ 
    /* base cases */
    if (root1 == NULL && root2 == NULL) 
        return true; 
  
    if (root1 == NULL || root2 == NULL) 
        return false; 
  
    /* Check if the data of both roots is 
    same and data of left and right 
    subtrees are also same */
    return (root1->data == root2->data && 
            areIdentical(root1->left, root2->left) && 
            areIdentical(root1->right, root2->right) ); 
} 
  
  
/* This function returns true if S 
is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S) 
{ 
    /* base cases */
    if (S == NULL) 
        return true; 
  
    if (T == NULL) 
        return false; 
  
    /* Check the tree with root as current node */
    if (areIdentical(T, S)) 
        return true; 
  
    /* If the tree with root as current 
    node doesn't match then try left 
    and right subtrees one by one */
    return isSubtree(T->left, S) || 
        isSubtree(T->right, S); 
} 

Approach-2:
void storeInorder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->data;
    storeInorder(root->right, arr, i);
}

// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

bool isSubTree(Node* T, Node* S)
{
    if (S == NULL)
    return true;
    if (T == NULL)
        return false;

    // Store Inorder traversals of T and S in inT[0..m-1]
    // and inS[0..n-1] respectively
    int m = 0, n = 0;
    char inT[MAX], inS[MAX];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';

    // If inS[] is not a substring of inT[], return false
    if (strstr(inT, inS) == NULL)
        return false;

    // Store Preorder traversals of T and S in preT[0..m-1]
    // and preS[0..n-1] respectively
    m = 0, n = 0;
    char preT[MAX], preS[MAX];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';

    // If preS[] is not a substring of preT[], return false
    // Else return true
    return (strstr(preT, preS) != NULL);
}
