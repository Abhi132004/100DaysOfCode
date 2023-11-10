// https://leetcode.com/submissions/detail/1095723477/
// 2265.Count Nodes Equal to Average of Subtree

class Solution {
public:

    int ans = 0;

    // sum,count
    pair<int,int> Ans(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        pair<int,int> leftSubTree = Ans(root->left); 
        pair<int,int> rightSubTree = Ans(root->right); 
        int sum = root->val + leftSubTree.first + rightSubTree.first;
        int count = 1 + leftSubTree.second + rightSubTree.second;
        int average = sum/count;
        if(root->val == average){
            ans+=1;
        }

        return {sum,count};

    }


    int averageOfSubtree(TreeNode* root) {
        Ans(root);
        return ans;

    }
};
