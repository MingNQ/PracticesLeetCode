#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

bool isUniqueChars(string s) {
	unordered_set<char> set;
	for(char c : s) {
		if (set.count(c))
			return false;
		
		set.insert(c);
	}
	
	return true;
}

void dfs(const vector<string> &arr, const string &path, int index, int &res) {
	if (isUniqueChars(path)) {
		res = max(res, static_cast<int>(path.length()));
	}
	
	if (index == arr.size() || !isUniqueChars(path))
		return ;
	
	for(int i = index; i < arr.size(); i++) {
		dfs(arr, arr[i] + path, i + 1, res);
	}
}

int maxLength(vector<string>& arr) {
	int res = 0;
	dfs(arr, "", 0, res);
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<string> arr = {"un","iq","ue"};
    
    cout << maxLength(arr);
}

