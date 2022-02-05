/*
    List of Depths: Given a binary tree, design an algorithm which creates a linked list of all nodes at each depth
    (e.g., If you hve a tree with depth Depth D, you'll have D linked list)
*/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *nextRight;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};


// Function for connecting the nodes of a tree 
void connectNodesAtLevel(TreeNode *root) {
    // If the root is null then return the root node
    if(!root) {
        return;
    }

    // Create queue for level order traversal
    queue<TreeNode*> q;
    q.push(root);

    vector<TreeNode*> levelOrderElements;

    // Start traversing the input tree in level order traversal    
    while(!q.empty()) {
        int size = q.size();
        levelOrderElements = vector<TreeNode*>();
        
        for(int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            levelOrderElements.push_back(node);
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }

        int levelNodeSize = levelOrderElements.size();
        if(levelNodeSize == 1) {
            levelOrderElements[0]->nextRight = nullptr;
        } else {
            // Connect the nextRight of every node to its adjacent node
            for(int i = 0; i < levelNodeSize - 1; i++) {
                levelOrderElements[i]->nextRight = levelOrderElements[i + 1];
            }
            levelOrderElements[levelNodeSize - 1]->nextRight = nullptr;
        }
    }
}
