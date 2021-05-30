struct Info {
    int lDepth;
    int rDepth;
    bool contains;

    int time;

    Info()
    {
        lDepth = rDepth = 0;
        contains = false;

        time = -1;
    }
};

/*  
    Function to calculate time required to burn 
    tree completely
    
    node - address of current node
    info - extra information about current node
    target - node that is fired
    res - stores the result
*/
Info calcTime(Node* node, Info& info, int target, int& res)
{

    // Base case: if root is null
    if (node == NULL) {
        return info;
    }

    // If current node is leaf
    if (node->left == NULL && node->right == NULL) {

        // If current node is the first burnt node
        if (node->data == target) {
            info.contains = true;
            info.time = 0;
        }
        return info;
    }

    // Information about left child of root
    Info leftInfo;
    calcTime(node->left, leftInfo, target, res);

    // Information about right child of root
    Info rightInfo;
    calcTime(node->right, rightInfo, target, res);

    // If left subtree contains the fired node then
    // time required to reach fire to current node
    // will be (1 + time required for left child)
    info.time = (node->left && leftInfo.contains) ? (leftInfo.time + 1) : -1;

    // If right subtree contains the fired node then
    // time required to reach fire to current node
    // will be (1 + time required for right child)
    if (info.time == -1)
        info.time = (node->right && rightInfo.contains) ? (rightInfo.time + 1) : -1;

    // Storing(true or false) if the tree rooted at
    // current node contains the fired node
    info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));

    // Calculate the maximum depth of left subtree
    info.lDepth = !(node->left) ? 0 : (1 + max(leftInfo.lDepth, leftInfo.rDepth));

    // Calculate the maximum depth of right subtree
    info.rDepth = !(node->right) ? 0 : (1 + max(rightInfo.lDepth, rightInfo.rDepth));

    // Calculating answer
    if (info.contains) {
        // If left subtree exists and
        // it contains the fired node
        if (node->left && leftInfo.contains) {
            // calculate result
            res = max(res, info.time + info.rDepth);
        }

        // If right subtree exists and it
        // contains the fired node
        if (node->right && rightInfo.contains) {
            // calculate result
            res = max(res, info.time + info.lDepth);
        }
    }
}

// Driver function to calculate minimum
// time required
int minTime(Node* root, int target)
{
    int res = 0;
    Info info;

    calcTime(root, info, target, res);

    return res;
}
