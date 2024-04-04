#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int maxProduct(vector<int>& nums) {
	sort(nums.begin(), nums.end(), greater<int>());
	
	return (nums[0] - 1)*(nums[1] - 1);         
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {1,5,4,5};
    
    cout << maxProduct(nums);
}

