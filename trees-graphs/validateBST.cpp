/*
    validate BST: Implement a function to check if a binary tree is a binary search tree
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// Function which checks if the the input is a BST or no
bool checkForBST(TreeNode *root, int min, int max) {
    if(!root) {
        return true;
    }

    // Condition for checking if the root->data satisfies the condition
    if(root->val <= min and root->val >= max) {
        return false;
    }

    // Function for checking if the input tree is a BST or no
    return checkForBST(root->left, min, root->val) and checkForBST(root->right, root->val, max);
}


// Function for checking if the input tree is BST or no
bool isBST(TreeNode *root) {
    if(!root) {
        return true;
    }
}