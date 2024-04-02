#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool closeStrings(string word1, string word2) {
	vector<int> freq1(26, 0);
	vector<int> freq2(26, 0);
	
	for(char c : word1) {
		freq1[c - 'a']++;
	}	
		
	for(char c : word2) {
		freq2[c - 'a']++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (freq1[i] == 0 &&  freq2[i] != 0 || freq1[i] != 0 && freq2[i] == 0) {
			return false;
		}
	}
	
	sort(freq1.begin(), freq1.end());
	sort(freq2.begin(), freq2.end());
	
	for (int i = 0; i < 26; i++) {
		if (freq1[i] != freq2[i])
			return false;
	}
	
	return true;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	string word1 = "cabbba";
	string word2 = "abbccc";
	
	cout << closeStrings(word1, word2); 
}

