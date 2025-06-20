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
    void preorderfunc(TreeNode* node,vector<int>& ans){
            if(node==nullptr) return;
            ans.push_back(node->val);
            preorderfunc(node->left,ans);
            preorderfunc(node->right,ans);
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderfunc(root,ans);
        return ans;
        
    }
};