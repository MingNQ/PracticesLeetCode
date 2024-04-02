#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

//bool makeEqual(vector<string>& words) {
//	unordered_map<char, int> mp;
//	
//	for(string word : words) {
//		for(char c : word) {
//			mp[c]++;	
//		}
//	}
//	
//	for(auto [key, val] : mp) {
//		if (val % words.size() != 0) return false;
//	}
//	return true;
//}

bool makeEqual(vector<string>& words) {
	vector<int> count(26, 0);
	
	for(string word : words) {
		for(char c : word) {
			count[c - 'a']++;
		}
	}
	int n = words.size();
	for(int x : count) {
		if (x % n != 0) return false;
	}
	return true;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<string> words = {"abc","aabc","bc"};
    
    cout << makeEqual(words);
}

