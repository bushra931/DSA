class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second;
            unsigned long long first = 0, last = 0;
            
            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front(); q.pop();
                unsigned long long curr_id = idx - mmin;
                if (i == 0) first = curr_id;
                if (i == size - 1) last = curr_id;

                if (node->left) {
                    q.push({node->left, curr_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, curr_id * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return static_cast<int>(ans);
    }
};
