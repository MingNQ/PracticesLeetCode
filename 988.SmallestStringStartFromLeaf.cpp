#include<iostream>
#include<queue>

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
        string smallestFromLeaf(TreeNode *root) {
            string res;
            dfs(root, "", res);
            return res;
        }

        void dfs(TreeNode *root, string s, string &res) {
            if (!root) return ;


            s = char(root->val + 'a') + s;

            if (!root->left && !root->right) {
                if (res == "" || res > s) {
                    res = s;
                }
            }

            if (root->left) 
                dfs(root->left, s, res);
            if (root->right)
                dfs(root->right, s, res);
        }

        // Approach 2: BFS
        string smallestFromLeaf_2(TreeNode *root) {
            string small;
            queue<pair<TreeNode*, string>> q;
            q.emplace(root, string(1, root->val + 'a'));
            
            while (!q.empty()) {
                auto [curr, currS] = q.front();
                q.pop();

                if (!curr->left && !curr->right) {
                    if (small == "") {
                        small = currS;
                    } else {
                        small = min(small, currS);
                    }
                }
                if (curr->left) 
                    q.push(curr->left, char(curr->left->val + 'a') + currS);
                if (curr->right)
                    q.push(curr->right, char(curr->right->val + 'a') + currS);
            }
        }

};

main() {
    
}