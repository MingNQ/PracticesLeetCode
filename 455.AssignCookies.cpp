#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	
	int i = 0;
	int j = 0;
	
	while(i < g.size() && j < s.size()) {
		if (s[j] >= g[i]) {
			i++;
		}
		j++;
	}
	
	return i;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    
    cout << findContentChildren(g, s);
}

