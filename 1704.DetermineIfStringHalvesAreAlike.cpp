#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool halvesAreAlike(string s) {
	unordered_set<char> vowels = {'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I'};
	int count = 0;
	int mid = s.length() / 2;
	
	for(int i = 0; i < mid; i++) {
		char a = s[i];
		char b = s[mid + i];
		if (vowels.count(a)) count++;
		if (vowels.count(b)) count--;
	}	  
	
	return count == 0;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s = "textbook";
    
    cout << halvesAreAlike(s);
}

