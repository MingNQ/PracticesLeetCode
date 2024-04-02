#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1 sort and count
//int reductionOperations(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	int max = nums[0];
//	int res = 0;
//	int up = 0;
//	
//	for(int i = 1; i < n; i++) {
//		if(nums[i] != nums[i - 1]) {
//			up++;
//		}
//		res += up;
//	}
//	
//	return res;
//}

// C2
int reductionOperations(vector<int>& nums) {
	vector<int> freq(50001, 0);
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		freq[nums[i]]++;
	}
	int res = 0, oper = 0; 
	for(int i = 50000; i >= 1; i--) {
		if(freq[i] > 0) {
			oper += freq[i];
			res += oper - freq[i];
		}
	}
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	vector<int> nums = {1, 1, 1};
	
	cout << reductionOperations(nums);
}

