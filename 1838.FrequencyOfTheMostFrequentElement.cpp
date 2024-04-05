#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1 - Sliding Window
//int maxFrequency(vector<int>& nums, int k) {
//	int n = nums.size();
//	sort(nums.begin(), nums.end());
//	int left = 0;
//	int res = 0;
//	long curr = 0;
//	
//	for(int right = 0; right < n; right++) {
//		long target = nums[right];
//		curr += target;
//		
//		while((right - left + 1) * target - curr > k) {
//			curr -= nums[left];
//			left++;
//		}
//		res = max(res, right - left + 1);
//	}        
//	
//	return res;
//}

// ==> C2 - Advance Sliding Window
int maxFrequency(vector<int>& nums, int k) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int left = 0;
	int res = 0;
	long curr = 0;
	
	for(int right = 0; right < n; right++) {
		long target = nums[right];
		curr += target;
		
		if((right - left + 1) * target - curr > k) {
			curr -= nums[left];
			left++;
		}
	}        
	
	return n - left;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	vector<int> nums = {1, 4, 8, 13};
	
	cout << maxFrequency(nums, 5);
}

