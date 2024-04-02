#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	string h1, h2;
	
	for(int i = 0; i < word1.size(); i++) {
		h1 += word1[i];
	} 
	for(int i = 0; i < word2.size(); i++) {
		h2 += word2[i];
	}
	if(h1.length() < h2.length() || h1.length() > h2.length) return false;
	int n = h1.length();
	for(int i = 0; i < n; i++) {
		if(h1[i] != h2[i]) return false;
	}
	return true;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<string> word1 = {"a", "cb"};
    vector<string> word2 = {"ab", "c"};
    
    cout << arrayStringsAreEqual(word1, word2);
}

