#include <bits/stdc++.h>

using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
	vector<string> res;
// ===C1
//	for(int i = 1; i <= n; i++) {
//		bool check = false;
//		for(int j = 0; j < target.size(); j++) {
//			if(target[j] == i) check = true;
//			if(i == target[target.size() - 1] && target[target.size() - 1] < n) {
//				res.push_back("Push");
//				return res;
//			}
//		}
//		if(i <= n) res.push_back("Push");
//		
//		if(!check) res.push_back("Pop");
//	}
//	

// ===C2
	int i = 1;
	
	for(auto x : target) {
		while(i < x) {
			res.push_back("Push");
			res.push_back("Pop");
			i++;
		}
		res.push_back("Push");
		i++;
	}



	return res;
}

void display(vector<string>& target) {
	for(auto x : target) cout << x << " ";
}


int main()
{
	vector<int> target;
	int n, m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x; 
		cin >> x;
		target.push_back(x);
	}
	
	cout << "n = "; cin >> n;
	
	
	vector<string> res = buildArray(target, n);
	display(res);
 	return 0;
}
