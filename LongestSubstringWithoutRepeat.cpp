#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int maxL = 0;
	int start = -1;
	vector<int> vt(256, -1);
	
	for(int i = 0; i < s.size(); i++) {
		if(vt[s[i]] > start) 
			start = vt[s[i]];
		vt[s[i]] = i;
		maxL = maxL > (i - start) ? maxL : (i - start);
	}
	
	return maxL;
}

int main()
{
	string s;
	getline(cin, s);
	
	cout << lengthOfLongestSubstring(s);
	
 	return 0;
}

