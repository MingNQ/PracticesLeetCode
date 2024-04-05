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

pair<int, int> dfs(TreeNode *root, int &res) {
	if (root == nullptr) {
		return {INT_MAX, INT_MIN};
	}
	
	auto left = dfs(root->left, res);
	auto right = dfs(root->right, res);
	
	int minVal = min(root->val, min(left.first, right.first));
	int maxVal = max(root->val, max(left.second, right.second));
	
	res = max({res, abs(minVal - root->val), abs(maxVal - root->val)});
	
	return {minVal, maxVal};
}

int maxAncestorDiff(TreeNode* root) {
	int res = 0;
	dfs(root, res);
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

