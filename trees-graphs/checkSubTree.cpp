/*
    Check Sub Tree: T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T1 is a subtree of T2

    A tree T2 is a subtree of T1 if there exist a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// Function for checking it two trees are identical
bool areIdentical(TreeNode *T1, TreeNode *T2) {
    if(!T1 and !T2) {
        return true;
    }

    if(!T1 or !T2) {
        return false;
    }

    return T1->val == T2->val and areIdentical(T1->left, T2->left) and areIdentical(T1->right, T2->right);
}

// Function for checking is a tree S is a subtree of tree T
bool isSubTree(TreeNode *T, TreeNode *S) {
    if(!S) {
        return true;
    }

    if(!T) {
        return false;
    }

    if(areIdentical(T, S)) {
        return true;
    }
    
    return isSubTree(T->left, S) or isSubTree(T->right, S);
}