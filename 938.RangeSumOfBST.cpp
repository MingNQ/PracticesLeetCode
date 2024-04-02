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

void sumHelper(TreeNode* root, int low, int high, int &res) {
	if (root == nullptr) return ;
	if (root->val >= low && root->val <= high) res += root->val;
	sumHelper(root->left, low, high, res);
	sumHelper(root->right, low, high, res);
}

int rangeSumBST(TreeNode* root, int low, int high) {
	int res = 0;
	sumHelper(root, low, high, res);
	
	return res;	        
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    TreeNode *root;
    root->val = 10;
    root->left = new TreeNode(5, new TreeNode(3), new TreeNode(7));
    root->right = new TreeNode(15, nullptr, new TreeNode(8));
    
    int low = 7;
    int high = 15;
    
    cout << rangeSumBST(root, low, high);
}

