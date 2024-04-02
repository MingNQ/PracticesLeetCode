#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool check(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
	
	return false;
}

// ==> C1
//string sortVowels(string s) {
//	string t;
//	int n = s.length();
//	
//	for(int i = 0; i < n; i++) {
//		if(check(s[i])) t += s[i];
//	}
//	
//	sort(t.begin(), t.end());
//	
//	int j = 0;
//	string res;
//	
//	for(int i = 0; i < n; i++) {
//		if(check(s[i])) {
//			s[i] = t[j];
//			j++;
//			res += s[i];
//		} else {
//			res += s[i];
//		}
//	}
//	
//	return res;
//}


// ==> C2
string sortVowels(string s) {
	int n = s.length();
	unordered_map<char, int> count;

	for(auto x : s) {
		if(check(x)) count[x]++;
	}
	
	string sorted = "AEIOUaeiou";
	int j = 0;
	string res;
	
	for(int i = 0; i < n; i++) {
		if(check(s[i])) {
			while(count[sorted[j]] == 0) {
				j++;
			}
			res += sorted[j];
			count[sorted[j]]--;
		} else {
			res += s[i];
		}
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s = "lEetcOde";
    
    cout << sortVowels(s);
}

