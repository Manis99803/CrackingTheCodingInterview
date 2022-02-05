/*
    Minimal tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
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

// Function for building the tree
TreeNode* buildTree(vector<int> &nums, int low, int high) {
    // If the low is greater than high, then return nullptr
    if(low > high) {
        return nullptr;
    }

    // Get the mid of the array
    int mid = (low + high) / 2;

    // Create a root node from the array
    TreeNode *root = new TreeNode(nums[mid]);

    // Build the left tree
    root->left = buildTree(nums, low, mid - 1);

    // Build the right tree
    root->right = buildTree(nums, mid + 1, high);
    
    // return the root
    return root;
}

// Function for buiding BST from sorted array, balanced binary tree
TreeNode *sortedArrayToBST(vector<int> &nums) {
    int low = 0;
    int high = nums.size();

    return buildTree(nums, low, high);
}