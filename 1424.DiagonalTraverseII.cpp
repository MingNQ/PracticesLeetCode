#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
	vector<int> res;
	unordered_map<int, vector<int>> groups;
	
	for(int i = nums.size() - 1; i >= 0; i--) {
		for(int j = 0; j < nums[i].size(); j++) {
			int diagonal = i + j; // store index of sum i + j
			groups[diagonal].push_back(nums[i][j]);
		}
	}   
	
	int curr = 0;
	// iterate curr from groups.begin() to end() and push each ele to ans
	while(groups.find(curr) != groups.end()) {
		for(int num : groups[curr]) {
			res.push_back(num);
		}
		curr++;
	}
	
	return res;
}
    
imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    
    vector<int> res = findDiagonalOrder(nums);
    
    for(auto x : res) cout << x << " ";
}

