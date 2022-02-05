/*
    Successor: Write an algorithm to find the "next" node (i.e, in-order successor) of a given node in a binary search tree. You may assume that each node links to its parent
*/


#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(nullptr), right(nullptr) {}
};

// Function for getting the inOrderSuccessor of a node
void inOrderSuccessor(TreeNode *root, TreeNode **prev, TreeNode **successor, int value) {
    if(!root) {
        return;
    }

    inOrderSuccessor(root->left, prev, successor, value);
    // If the previous is not null then the current node is the successor
    if(*prev) {
        *successor = root;
        *prev = nullptr;
    } else {
        if(root->val == value) {
            *prev = root;
        }
    }
    inOrderSuccessor(root->right, prev, successor, value);
}


TreeNode *inOrderSuccessor(TreeNode *root, TreeNode *node) {
    TreeNode *prev = nullptr;
    TreeNode *successor = nullptr;

    inOrderSuccessor(root, &prev, &successor, node->val);
    
    return successor;
}