/*
    First Common Ancestor: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data strcuture.
    Note: This is not necessarily a binary search tree
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

TreeNode *lca(TreeNode *root, int n1, int n2) {
    // If the root is null then return the root
    if(!root) {
        return root;
    }

    if(root->val == n1 or root->val == n2) {
        return root;
    }

    // Get left and right LCA
    TreeNode *leftLCA = lca(root->left, n1, n2);
    TreeNode *rightLCA = lca(root->right, n1, n2);

    // If left and right LCA both doesn't return null, then that is LCA
    if(leftLCA and rightLCA) {
        return root;
    }
    
    return leftLCA ? leftLCA : rightLCA;
}