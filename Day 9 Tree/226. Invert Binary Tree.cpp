// Problem Link :- https://leetcode.com/problems/invert-binary-tree/

// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL)
            return root;
        
        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL)
            return root;
        
        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            swap(node->left, node->right);

            if (node->left)
                q.emplace(node->left);
            
            if (node->right)
                q.emplace(node->right);
        }

        return root;
    }
};