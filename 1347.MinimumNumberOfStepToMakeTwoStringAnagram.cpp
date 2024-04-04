#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int minSteps(string s, string t) {
	unordered_map<char, int> dic1;
	unordered_map<char, int> dic2;
	
	for(char c : s) {
		dic1[c]++;
	}       
	
	for(char c : t) {
		dic2[c]++;
	}
	int res = 0;
	
	for(int i = 0; i < 27; i++) {
		res += abs(dic1[i + 'a'] - dic2[i + 'a']);
	}
	
	return res / 2;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	string s = "anagram";
	string t = "mangaar";
	
	cout << minSteps(s, t);
	
}

