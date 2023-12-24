// https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum){

        if(root == NULL){
            return false;
        }

        if(root->left == nullptr && root->right == nullptr){
            return targetSum == root->val;
        }

        int sum = targetSum - root->val;

        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);

    }
};
