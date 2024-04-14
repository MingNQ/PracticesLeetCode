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
    // Approach 1: BFS 
        int sumOfLeaftLeaves(TreeNode *root) {
            if (root->left == nullptr && root->right == nullptr) return 0;
            int res = 0;
            queue<TreeNode*> q;

            q.push(root);

            while (!q.empty()) {
                TreeNode *curr = q.front();
                q.pop(); 

                if (curr->left != nullptr) {
                    if (!curr->left->left && !curr->left->right) {
                        res += curr->left->val;
                    }
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            return res;
        }

    // Approach 2: DFS
        int sumOfLeaftLeaves_dfs(TreeNode*root) {
            if (root->left == nullptr && root->right == nullptr) return 0;
            int res = 0;
            dfs(root, res);
            return res;
        }
        void dfs(TreeNode* root, int &res) {
            if (!root) return ;

            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    res += root->left->val;
                }
                dfs(root->left, res);
            }
            if (root->right) {
                dfs(root->right, res);
            }
        }
};