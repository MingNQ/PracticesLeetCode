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

void preOrder(TreeNode *root, string &s) {
	if (root != nullptr) {
		s += to_string(root->val);
		
		if (root->left || root->right) {
			s += "(";
			preOrder(root->left, s);
			s += ")";
		}
		
		if (root->right) {
			s += "(";
			preOrder(root->right, s);
			s += ")";
		}
			
	}
}

string tree2str(TreeNode* root) {  
	string s = "";
	preOrder(root, s);
	
	return s;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2, node4, nullptr);
    TreeNode *node3 = new TreeNode(3);
	TreeNode *root = new TreeNode(1, node2, node3);
    
    cout << tree2str(root);
}

