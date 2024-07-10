// Problem Link :- https://leetcode.com/problems/subtree-of-another-tree/

// Solved by DFS
// Time Compelxity :- O(n * m)  n = no. of nodes in main tree
// Space Complexity :- O(n + m)  m = no. of nodes in subtree

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

    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool subRootFound = false) {
        
        if (subRootFound)
        {
            if (root == NULL && subRoot == NULL)
                return true;

            if (root == NULL || subRoot == NULL || root->val != subRoot->val)
                return false;

            return isSubtree(root->left, subRoot->left, true) && isSubtree(root->right, subRoot->right, true);
        }

        if (root == NULL || subRoot == NULL)
            return false;

        bool matchFound = false;

        if (root->val == subRoot->val)
            matchFound = isSubtree(root, subRoot, true);

        return matchFound || isSubtree(root->left, subRoot, false) || isSubtree(root->right, subRoot, false);
    }
};