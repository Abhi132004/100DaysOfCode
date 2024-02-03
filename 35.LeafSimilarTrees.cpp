// https://leetcode.com/problems/leaf-similar-trees/?envType=study-plan-v2&envId=leetcode-75

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

    void leafCrack(TreeNode* root , string &s){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            s+=root->val;
        }
        leafCrack(root->left , s);
        leafCrack(root->right , s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        leafCrack(root1 , s1);
        leafCrack(root2 , s2);

        return s1==s2;



    }
};
