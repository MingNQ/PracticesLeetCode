#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int minPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int res = 0;
	for(int i = 0; i < n /2; i++) {
		int max = nums[i] + nums[n - i - 1];
		if(max > res) res = max;
	}  
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {3,5,4,2,4,6};
    
    cout << minPairSum(nums);
}

