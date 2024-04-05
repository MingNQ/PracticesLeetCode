#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1: greedy
int maxCoins(vector<int>& piles) {
	int n = piles.size() / 3;
	
	sort(piles.begin(), piles.end());
	
	vector<int> newPiles(piles.begin() + n, piles.end());
	
	int res = 0;
	
	for(int i = 0; i < newPiles.size(); i += 2) {
		res += newPiles[i];
	}       
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> piles = {9,8,7,6,5,1,2,3,4};
    
    cout << maxCoins(piles);
}

