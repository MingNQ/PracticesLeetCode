#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int robNext(int i, vector<int>& nums) {
	return nums[i] + nums[i + 2];
}

int rob(vector<int>& nums) {
	int res = 0;
	
	for(int i = 0; i < nums.size() / 2; i++) {
		int sum = max(robNext(i, nums), res);
		res += sum;
	}	        
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {1,2,3,1};
    
    cout << rob(nums);
}

