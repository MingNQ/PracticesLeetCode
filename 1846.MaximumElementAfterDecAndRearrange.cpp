#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1
//int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//	sort(arr.begin(), arr.end());
//	
//	if (arr[0] != 1) arr[0] = 1;
//	
//	for(int i = 1; i < arr.size(); i++) {
//		if ((abs(arr[i]) - abs(arr[i - 1])) > 1) {
//			arr[i] = abs(arr[i - 1]) + 1;
//		}
//	}
//	
//	return arr[arr.size() - 1];        
//}

// ==> C2
//int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//    sort(arr.begin(), arr.end());
//    int ans = 1;
//        
//    for (int i = 1; i < arr.size(); i++) {
//        if (arr[i] >= ans + 1) {
//            ans++;
//        }
//    }
//        
//	return ans;
//}

// ==> C3
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
	int n = arr.size();
	vector<int> count(n + 1, 0);
	
	for(int num : arr) {
		count[min(num, n)]++;
	}
	
	int res = 1;
	for(int num = 2; num <= n; num++) {
		res = min(res + count[num], num);
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> arr = {1,2,3,4,5};
    
    cout << maximumElementAfterDecrementingAndRearranging(arr);
}

