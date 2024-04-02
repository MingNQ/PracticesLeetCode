#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

string reverseStr(string s, int k) {
	int n = s.length(); 
//	string res;
//	string t;
	
	for(int i = 0; i < n; i += 2*k) {
		int left = i;
		int right = min(i + k - 1, n - 1);
		
		while(left < right) {
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}   
	
	return s;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "abcdefg";
	cout << reverseStr(s, 2);
}

