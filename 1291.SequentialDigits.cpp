#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

void print(vector<int> a) {
	for(int x : a) 
		cout << x << " ";
}

//vector<int> sequentialDigits(int low, int high) {
//	string c = "123456789";
//	vector<int> res;
//	
//	for(int i = 0; i < c.size(); i++) {
//		for(int j = i + 1; j <= c.size(); j++) {
//			int curr = stoi(c.substr(i, j - i));
//			
//			if (curr <= high && curr >= low) res.push_back(curr);	
//		}										
//	}
//	
//	sort(res.begin(), res.end());
//	
//	return res;
//} 

//vector<int> sequentialDigits(int low, int high) {
//	vector<int> res;
//	
//	for(int i = 1; i <= 9; i++) {
//		int num = i;
//		int next = i + 1;
//		
//		while(num <= high && next <= 9) {
//			num = num*10 + next;
//			if (num >= low && num <= high) res.push_back(num);
//			next++;
//		}
//	}
//	
//	sort(res.begin(), res.end());
//	
//	return res;
//}

vector<int> res;

void dfs(int low, int high, int num, int i) {
	if (num <= high && num >= low) res.push_back(num);
	
	if (num > high || i > 9) 
		return;
		
	dfs(low, high, num*10 + i, i + 1);
}

vector<int> sequentialDigits(int low, int high) {
	for(int i = 1; i <= 9; i++) {
		dfs(low, high, 0, i);
	}
	
	sort(res.begin(), res.end());
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int low = 1000;
	int high = 13000;
	
	print(sequentialDigits(low, high));
	
}

