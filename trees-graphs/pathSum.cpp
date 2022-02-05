/*
    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along with the path equals targetSum.
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right)  {}
};

void preOrderTraversal(TreeNode *root, int sum, int *sumUntilNow, bool *doesPathSumExist) {
    // If the path sum exist then the we don't need to traverse further
    if(*doesPathSumExist) {
        return;
    }

    // If the root is null return
    if(!root) {
        return;
    }

    // Keep adding the value of the sumUntilNow
    *sumUntilNow += root->val;
    if(!root->left and !root->right) {
        if(*sumUntilNow == sum) {
            *doesPathSumExist = true;
        }
    }

    // Continue the preOrderTraversal
    preOrderTraversal(root->left, sum, sumUntilNow, doesPathSumExist);
    preOrderTraversal(root->right, sum, sumUntilNow, doesPathSumExist);
}



// Function to check if the path sum exist from root to leaf
bool hasPathSum(TreeNode *root, int sum) {
    if(!root) {
        return false;
    }

    // variable for keeping track if there is path in the tree
    bool doesPathExist = false;
    // variable for keeping track if the sum from the root exist
    int sumUntilNow = 0;

    preOrderTraversal(root, sum, &sumUntilNow, &doesPathExist);

    return doesPathExist;
}