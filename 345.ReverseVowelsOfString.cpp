#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool check(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        
    return false;
} 

string reverseVowels(string s) {
	int n = s.length(); 
	string t;
	
	for(auto x : s) if(check(x)) t += x;
	
	reverse(t.begin(), t.end());
	
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(check(s[i])) {
			s[i] = t[j];
			j++;
		}
	}
	
	return s;        
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "leetcode";
	cout << reverseVowels(s);
}

