#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int minOperations(vector<int>& nums) {
	unordered_map<int, int> count;
	
	for(int x : nums) {
		count[x]++;
	}
	
	int res = 0;
	
	for(auto &it : count) {
		if (it.second < 2) return -1;
		
		if (it.second % 3 == 0) {
			res += it.second / 3;
		} else {
			res += it.second / 3 + 1;
		}
	}
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {19,19,19,19,19,19,19,19,19,19,19,19,19};
    
    cout << minOperations(nums);
}

