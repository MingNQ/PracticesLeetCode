#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

string reverseWords(string s) {
	int n = s.length(); 
	stringstream ss(s);
	string t;
	string res;
	
	for(int i = 0; i < n ; i++) {
		if(s[i] == ' ') {
			reverse(t.begin(), t.end());
			res += t;
			res += s[i];
			t = "";
		} else if (s[i + 1] == '\0'){
			t += s[i];
			reverse(t.begin(), t.end());
			res += t;
			t = "";
		} else {
			t += s[i];
		}
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "Let's take LeetCode contest";
	cout << reverseWords(s);
}

