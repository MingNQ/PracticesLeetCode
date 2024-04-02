#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

//int minCost(string colors, vector<int>& neededTime) {
//	int n = colors.length();
//	char preColor = 'a';
//	int preTime = 0;
//	int currCost = 0, preCost = 0;
//	
//	for(int i = 1; i <= n; i++) {
//		if (colors[i - 1] == preColor) {
//			currCost = preCost + min(neededTime[i - 1], preTime);
//			preTime = max(neededTime[i - 1], preTime);
//		} else {
//			preColor = colors[i - 1];
//			currCost = preCost;
//			preTime = neededTime[i - 1];
//		}
//		preCost = currCost;
//	}
//	
//	return currCost;
//}

int minCost(string colors, vector<int>& neededTime) {
	int sum = 0;
	int pre = 0;
	int n = colors.length();
	
	for(int i = 1; i <= n; i++) {
		if (colors[pre] != colors[i]) {
			pre = i;
		} else {
			if (neededTime[pre] < neededTime[i]) {
				sum += neededTime[pre];
				pre = i;
			} else {
				sum += neededTime[i];
			}
		}
	}
	
	return sum;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string colors = "cddcdcae";
    vector<int> neededTime = {4,8,8,4,4,5,4,2};
    
    cout << minCost(colors, neededTime);
}

