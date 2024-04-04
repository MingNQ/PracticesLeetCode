#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int findSpecialInteger(vector<int>& arr) {
	int n = arr.size();
	float rate = 0.25 * n;
	unordered_map<int, int> count;
	
	for(int i = 0; i < n; i++) {
		count[arr[i]]++;
	}         
	
	int max = 0;
	for(auto x : count) {
		if (x.second > rate && x.second > max) {
			max = x.first;
		}
	}
	return max;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> arr = {1,1};
    
    cout << findSpecialInteger(arr);
}

