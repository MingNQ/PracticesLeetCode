#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1 Sorting
//vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
//	int m = l.size();
//	int n = nums.size();
//	
//	vector<bool> res;
//	
//	for(int i = 0; i < m; i++) {
//		vector<int> a(nums.begin() + l[i], nums.begin() + r[i] + 1);
//		sort(a.begin(), a.end());
//		int tmp = a[1] - a[0];
//		bool check = true;
//		for(int j = 2; j < a.size(); j++) {
//			if(a[j] - a[j - 1] != tmp) {
//				check = false;
//			}
//		}
//	
//		res.push_back(check); 
//	}  
//	return res;
//}
   
// ==> C2 No sorting
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
	vector<bool> res;
	
	for(int i = 0; i < l.size(); i++) {
		vector<int> a(nums.begin() + l[i], nums.begin() + r[i] + 1);
		bool check = true;
		int minElem = INT_MAX;
		int maxElem = INT_MIN;
		unordered_set<int> arrSet;
		
		for(int num : a) {
			minElem = min(minElem, num);
			maxElem = max(maxElem, num);
			arrSet.insert(num);
		}
		
		if((maxElem - minElem) % (a.size() - 1) != 0) check = false;
		
		int diff = (maxElem - minElem) / (a.size() - 1);
		int curr = minElem + diff;
		
		while(curr < maxElem) {
			if(arrSet.find(curr) == arrSet.end()) {
				check = false;
			}
			curr += diff;
		}
		
		res.push_back(check);
	}
	
	return res;
}   
    
imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> nums = {4,6,5,9,3,7};
	vector<int> l = {0,0,2};
	vector<int> r = {2,3,5};
	vector<bool> res = checkArithmeticSubarrays(nums, l, r);
	
	for(auto x : res) cout << x << " ";
}

