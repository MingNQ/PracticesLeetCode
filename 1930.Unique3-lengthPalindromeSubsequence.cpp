#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1
//int countPalindromicSubsequence(string s) {
//	unordered_set<char> letters;
//	int res = 0;
//	for(char c : s) letters.insert(c);
//	
//	for(char letter : letters) {
//		int i = -1;
//		int j = 0;
//		
//		for(int k = 0; k < s.length(); k++) {
//			if(s[k] == letter) {
//				if(i == -1) i = k;
//				
//				j = k;
//			}
//		}
//		
//		unordered_set<char> between;
//		
//		for(int k = i + 1; k < j; k++) {
//			between.insert(s[k]);
//		}
//		
//		res += between.size();
//	}        
//	return res;
//}


//==> C2
int countPalindromicSubsequence(string s) {
	int res = 0;
	vector<int> first(26, -1);
	vector<int> last(26, -1);
	
	for(int i = 0; i < s.length(); i++) {
		int curr = s[i] - 'a';
		
		if(first[curr] == -1) {
			first[curr] = i;
		}
		
		last[curr] = i;
	}
	
	for(int i = 0; i < 26; i++) {
		if(first[i] == - 1) continue; // skip character doesn't appear
		
		unordered_set<char> between;
		for(int j = first[i] + 1; j < last[i]; j++) {
			between.insert(s[j]);
		}
		res += between.size();
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s = "bbcbaba";
    cout << countPalindromicSubsequence(s);
}

