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
     TreeNode* build(vector<int>& postorder,int ps,int pe, vector<int>& inorder,int instart,int inend,map<int,int>& inmap){
        if(ps>pe || instart>inend) return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=inmap[root->val];
        int numsleft=inroot-instart;
        
        root->left=build(postorder,ps,ps+numsleft-1,inorder,instart,inroot-1,inmap);
        root->right=build(postorder,ps+numsleft,pe-1,inorder,inroot+1,inend,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
        
    }
};