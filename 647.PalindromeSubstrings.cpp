#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// Brute Force
//bool isPalindrome(string s, int left, int right) {
//	while(left < right) {
//		if (s[left++] != s[right--]) 
//			return false;
//	}
//	return true;
//}
//
//int countSubstrings(string s) {
//	int res = 0;
//	
//	int n = s.length();
//	
//	for(int i = 0; i < n; i++) {
//		for(int j = i; j < n; j++) {
//			if (isPalindrome(s, i, j)) res++;
//		}
//	}        
//	
//	return res;
//}

int palindrome(string s, int left, int right) {
	int count = 0;
	
	while(left >= 0 && right < s.length() && s[left] == s[right]) {
		left--;
		right++;
		count++;
	}
	
	return count;
}

int countSubstrings(string s) {
	int n = s.length();
	int res = 0;
	for(int i = 0; i < n; i++) {
		int odd = palindrome(s, i, i + 1);
		int even = palindrome(s, i, i);
		res += odd + even;
	}
	return res;
}


imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	string s = "aaa";
	
	cout << countSubstrings(s);
}

