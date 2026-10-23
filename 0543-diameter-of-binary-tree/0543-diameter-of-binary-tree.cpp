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
    int diameterOfBinaryTree(TreeNode* root) {
       int maxDia = 0;
       calculate(root, maxDia);

        return maxDia; 
    }
    int calculate(TreeNode* root, int& maxDia) {
        if(root == nullptr) return 0;

        int leftDiameter = calculate(root->left, maxDia);
        int rightDiameter = calculate(root->right, maxDia);

        maxDia = max(leftDiameter+rightDiameter, maxDia);

        return 1 + max(leftDiameter, rightDiameter);
    }
};