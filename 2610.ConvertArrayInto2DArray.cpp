#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

//vector<vector<int>> findMatrix(vector<int>& nums) {
//	vector<int> freq(nums.size() + 1);
//        
//    vector<vector<int>> ans;
//    for (int c : nums) {
//        if (freq[c] >= ans.size()) {
//            ans.push_back({});
//        }
//            
//        // Store the integer in the list corresponding to its current frequency.
//        ans[freq[c]].push_back(c);
//        freq[c]++;
//    }
//        
//    return ans;
//}

vector<vector<int>> findMatrix(vector<int>& nums) {
	unordered_map<int, int> mp;
	vector<vector<int>> res;
	
	for(int num : nums) {
		mp[num]++;
	}  
	
	for(auto it : mp) {
		cout << it.first << " " << it.second << endl;
	}
	
	for(auto it : mp) {
		if (it.second > res.size()) res.push_back({});
		for(int i = 0; i < it.second; i++) {
			res[i].push_back(it.first);
		} 
	}
	
	return res;
}

void print(vector<vector<int>>& mtx) {
	for(int i = 0; i < mtx.size(); i++) {
		for(int j = 0; j < mtx[i].size(); j++) {
			cout << mtx[i][j] << " ";
		}
		cout << endl;
	}
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	vector<int> nums = {1,3,4,1,2,3,1};
	
	vector<vector<int>> mtx = findMatrix(nums);
	print(mtx);
}

