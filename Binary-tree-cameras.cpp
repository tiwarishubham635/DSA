// https://leetcode.com/problems/binary-tree-cameras/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*
    we will be having three types of state
    1-> i am being covered by some node with a camera, CAM not reqd
    0-> i am having a camera already
    -1-> i need a camera, CAM reqd
    
    now from every node we will return one of the three values depending on their condition
    
    */
    
    int ans=0;
    
    int camState(TreeNode* root)
    {
        if(root == NULL) // null does not req CAM
            return 1;
        
        int leftcam = camState(root->left);
        int rightcam = camState(root->right);
        
        if(leftcam == -1 or rightcam == -1) // any child req CAM
        {
            // Icreasing the cam count to give a cam to this node
            ans++;
            // This node will have a camera
            return 0;
        }
        
        if(leftcam == 0 or rightcam == 0) 
        // anychild has cam, then this node is covered in that
            return 1;
        
        return -1; // else we need cam
        
    }
    
    int minCameraCover(TreeNode* root) {
        int cam = camState(root);
        if(cam == -1) // root needs a camera as it is not covered by other cameras
            ans++;
        return ans;
    }
};
