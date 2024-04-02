#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

string finalString(string s) {
	int n = s.length();
	string res;
	
	for(int i = 0; i < n; i++) {
		if(s[i] == 'i') reverse(res.begin(), res.end());
		else {
			res += s[i];
		}
	}        
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "poiinter";
	cout << finalString(s);
}

