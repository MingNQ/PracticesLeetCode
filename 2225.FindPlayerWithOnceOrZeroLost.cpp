#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
	unordered_map<int, int> countLose;
	vector<int> onceLost;
	vector<int> noLost;
	
	for(int i = 0; i < matches.size(); i++) {
		countLose[matches[i][1]]++;
	}   
	
	for(int i = 0; i < matches.size(); i++) {
		int win = matches[i][0];
		int lose = matches[i][1];
		
		if (countLose.find(win) == countLose.end()) {
			noLost.push_back(win);
			countLose[win] = 2;
		}
		if (countLose[lose] == 1) {
			onceLost.push_back(lose);
		}
	}	
	
	sort(noLost.begin(), noLost.end());
	sort(onceLost.begin(), onceLost.end());

	return {noLost, onceLost};
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

