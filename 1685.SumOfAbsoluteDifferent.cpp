#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
	int n = nums.size();
	vector<int> res;
	vector<int> prefix = {nums[0]};
	
	for(int i = 1; i < n; i++) {
		prefix.push_back(prefix[i - 1] + nums[i]);
	}
	
	for(int i = 0; i < n; i++) {
		int leftSum = prefix[i] - nums[i];
		int rightSum = prefix[n - 1] - prefix[i];
		
		int leftCount = i;
		int rightCount = n - i - 1;
		
		int leftTotal = leftCount * nums[i] - leftSum;
		int righTotal = rightSum - rightCount * nums[i];
		
		res.push_back(leftTotal + righTotal);
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {1,4,6,8,10};
    vector<int> res = getSumAbsoluteDifferences(nums);
    
    for(int x : res) cout << x << " ";
}

