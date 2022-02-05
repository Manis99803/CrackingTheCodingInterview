/*
    Check Balanced: Implement a function to check if a binary tree is balanced. For the purpose of this question, a balanced tree is defined to be a tree such that
    the heights of two subtrees of any node never differ by more than one
*/

#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// Function to check if a tree is balanced or no
bool isBalanced(TreeNode *root, int *height) {
    // If the root is null then the height of the tree is zero
    if(!root) {
        *height = 0;
        return true;
    }

    // Get left and right height
    int leftHeight = 0;
    int rightHeight = 0;
    
    int l = 0;
    int r = 0;

    // Get the leftHeight and rightHeight
    l = isBalanced(root, &leftHeight);
    r = isBalanced(root, &rightHeight);

    // Get the left and rightHeight of the tree
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // Get the difference between the left and rightHeight
    if(abs(leftHeight - rightHeight) >= 2) {
        return false; 
    } else {
        return l && r;
    }
}