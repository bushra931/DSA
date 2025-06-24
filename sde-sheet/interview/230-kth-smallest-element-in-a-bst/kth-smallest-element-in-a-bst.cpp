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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int ans = -1;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                cnt++;
                if (cnt == k) ans = curr->val; // ❗Don't return yet
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = curr; // create thread
                    curr = curr->left;
                } else {
                    prev->right = nullptr; // remove thread
                    cnt++;
                    if (cnt == k) ans = curr->val; // ❗Don't return yet
                    curr = curr->right;
                }
        }
        }
        return ans; // ✅ Safe return after all threads are removed
    }
};


