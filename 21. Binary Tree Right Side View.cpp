
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
#include <vector>

class Solution {
public:
    // Helper function for recursive traversal
    void rightHelper(TreeNode* root, vector<int>& check, int depth) {
        // Base case: If the current node is NULL, return
        if (root == NULL) {
            return;
        }
        // Check if the size of the vector is equal to the current depth
        if (check.size() == depth) {
            // If this is the first node encountered at this depth, add it to the result
            check.push_back(root->val);
        }
        // Traverse the right subtree first, so that rightmost nodes are encountered first
        rightHelper(root->right, check, depth + 1);
        // traverse the left subtree for right side view
        rightHelper(root->left, check, depth + 1);
    }

    // Main function to get the right side view of the binary tree
    vector<int> rightSideView(TreeNode* root) {
        // Vector to store the result (right side view)
        vector<int> check;
        // Call the helper function with initial depth 0
        rightHelper(root, check, 0);
        // Return the result vector
        return check;
    }
};
