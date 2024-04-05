#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int countCharacters(vector<string>& words, string chars) {
	unordered_map<char, int> counts;
	
	for(char c : chars) counts[c]++;
	
	int res = 0;
	
	for(string word : words) {
		unordered_map<char, int> wordCount;
		
		for(char c : word) {
			wordCount[c]++;
		}
		
		bool good = true;
		for(auto& [c, freq] : wordCount) {
			if (count[c] < freq) {
				good = false;
				break;
			}
		}
		
		if (good) {
			res += word.size();
		}
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

