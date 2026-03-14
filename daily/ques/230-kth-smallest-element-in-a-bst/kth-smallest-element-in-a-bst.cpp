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
    int inorder(TreeNode* root,int& cnt,int k){
        if(root==nullptr) return -1;
        int leftResult =inorder(root->left,cnt,k);
        if(leftResult != -1) return leftResult;
         cnt++;
        if(cnt==k) return root->val; 
        return inorder(root->right,cnt,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        //inorder
        int cnt=0;
        return inorder(root,cnt,k);


        
    }
};