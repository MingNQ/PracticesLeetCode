#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root1, vector<int>& leaves) {
	if (root1 == nullptr) return ;
	if (root1->left == nullptr && root1->right == nullptr)
		leaves.push_back(root1->val);
	dfs(root1->left, leaves);
	dfs(root1->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<int> leaves1;
	vector<int> leaves2;
	dfs(root1, leaves1);
	dfs(root2, leaves2);
	
	return leaves1 == leaves2;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

