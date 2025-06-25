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
    class NodeValue {
    public:
        int minNode, maxNode, sum;
        bool isBST;
        NodeValue(bool isBST, int minNode, int maxNode, int sum) {
            this->isBST = isBST;
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
        }
    };

    int maxSum = 0;

    NodeValue dfs(TreeNode* root) {
        if (!root) return NodeValue(true, INT_MAX, INT_MIN, 0);

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return NodeValue(true, min(root->val, left.minNode), max(root->val, right.maxNode), currSum);
        }

        return NodeValue(false, 0, 0, 0); // invalid BST
    }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum; 
    }
};