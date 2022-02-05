/*
    Binary Tree Paths: Given the root of the binary tree, return all root-to-leaf paths in any order. 
    A leaf is a node with no children.
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


// Function for printing all the paths from root to leaf
void treePath(TreeNode *root, vector<string> &paths, vector<string> &individualPath) {
    // If the root is null then return
    if(!root) {
        return;
    }

    // appending every node to the individual path
    individualPath.push_back(to_string(root->val));
    
    // If the current node is leaf node, then append the entire path to the path array
    if(!root->left and !root->right) {
        string path;
        int size = individualPath.size();
        for(int i = 0; i < size - 1; i++) {
            path += individualPath[i] + "->";
        }
        path += individualPath[size - 1];
    }
    
    treePath(root->left, paths, individualPath);
    treePath(root->right, paths, individualPath);

    individualPath.pop_back();
}

// Function for getting the binaryTreePaths.
vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> paths;
    vector<string> individualPath;

    treePath(root, paths, individualPath);
    return paths;
}