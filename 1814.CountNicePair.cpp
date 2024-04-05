#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int mod = 1e9 + 7;

int rev(int num) {
	int rev_num = 0;
	while(num != 0) {
		int temp = num % 10;
		rev_num = rev_num * 10 + temp;
		num /= 10;
	}
	return rev_num;
}

// ==> C1 Counting by Hash Map
//int countNicePairs(vector<int>& nums) {
//	int n = nums.size();
//	int res = 0;
//	unordered_map<int, int> freq;
//	vector<int> arr;
//	
//	for(int i = 0; i < n; i++) {
//		arr.push_back(nums[i] - rev(nums[i]));
//	}
//	
//	for(int num : arr) {
//		res = (res + freq[num]) % mod;
//		freq[num]++;
//	}
//	
//	return res;
//}

// ==> C2
int countNicePairs(vector<int>& nums) {
	int n = nums.size();
	
	for(int i = 0; i < n; i++) {
		nums[i] = nums[i] - rev(nums[i]);
	}
	
	sort(nums.begin(), nums.end());
	
	long count = 0;
	long res = 0;
	for(int i = 0 ; i < n - 1; i++) {
		count = 1;
		while (i < n - 1 && nums[i] == nums[i + 1]) {
            count++;
            i++;
        }
		res = (res % mod + (count * (count - 1) / 2 )) % mod;
	}
	
	return res % mod;
}


imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {42,11,1,97};
    
    cout << countNicePairs(nums);
}

