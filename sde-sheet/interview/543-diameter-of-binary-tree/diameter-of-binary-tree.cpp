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
    int findmax(TreeNode* node,int& maxi){
        if(node==nullptr) return 0;
        int lh=findmax(node->left,maxi);
        int rh=findmax(node->right,maxi);
        maxi=max(maxi,rh+lh);
        return 1+max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findmax(root,diameter);
        return diameter;   
    }
};