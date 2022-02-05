/*
    Paths With Sum: You are given a binary tree in which each node contains an integer value(which might be positive or negative). Design an algorithm to count the number of paths that sum
    to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (travelling only from parent nodes to child nodes)
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode *root, vector<int> &individualPath, vector<vector<int>> &paths, int sum, int *sumUntilNow) {
    if(!root) {
        return;
    }
    // Append each individual node to the individualPath vector
    individualPath.push_back(root->val);
    *sumUntilNow += root->val;

    // If the node is leaf node then check the sum until path
    if(!root->left and !root->right) {
        if(sum == *sumUntilNow) {
            paths.push_back(individualPath);
        }
    }

    // Pre order traversal on the input tree
    preOrderTraversal(root->left, individualPath, paths, sum, sumUntilNow);
    preOrderTraversal(root->right, individualPath, paths, sum, sumUntilNow);
    
    *sumUntilNow -= root->val;
    individualPath.pop_back();
}


// Function to get the path sum of the tree, get individual path
vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> paths;
    vector<int> individualPath;

    int *sumUntilNow = 0;

    preOrderTraversal(root, individualPath, paths, sum, sumUntilNow);
    return paths;
}
