#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        // Approach 1: DFS
        TreeNode* addOneRow(TreeNode* root, int val, int depth) {
            if (depth == 1) {
                TreeNode* curr = new TreeNode(val);
                curr->left = root;
                return curr;
            }

            dfs(root, val, depth, 1);

            return root;
        }

        void dfs(TreeNode* root, int val, int depth, int currDepth) {
            if (!root) return ;

            if (currDepth == depth - 1) {
                TreeNode* currLeft = root->left;
                TreeNode* currRight = root->right;

                root->left = new TreeNode(val);
                root->right = new TreeNode(val);

                if (currLeft) root->left->left = currLeft;
                if (currRight) root->right->right = currRight;
            }
            dfs(root->left, val, depth, currDepth + 1);
            dfs(root->right, val, depth, currDepth + 1);
        }

        // Approach 2: BFS
        TreeNode* addOneRow_2(TreeNode* root, int val, int depth) {
            if (depth == 1) {
                TreeNode* curr = new TreeNode(val);
                curr->left = root;
                return curr;
            }

            queue<pair<TreeNode*, int>> q;
            q.emplace(root, 1);

            while (!q.empty()) {
                auto [curr, level] = q.front();
                q.pop();

                if (level == depth - 1) {
                    TreeNode* currLeft = root->left;
                    TreeNode* currRight = root->right;

                    root->left = new TreeNode(val);
                    root->right = new TreeNode(val);

                    if (currLeft) root->left->left = currLeft;
                    if (currRight) root->right->right = currRight;
                } else {
                    if (curr->left) q.emplace(curr->left, level + 1);
                    if (curr->right) q.emplace(curr->right, level + 1);
                }
            }
            return root
        }
};

main() {
    
}