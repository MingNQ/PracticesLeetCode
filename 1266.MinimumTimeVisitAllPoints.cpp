#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
	int ans = 0;
	for(int i = 0; i < points.size() - 1; i++) {
		int currX = points[i][0];
		int currY = points[i][1];
		int targetX = points[i + 1][0];
		int targetY = points[i + 1][1];
		ans += max(abs(targetX - currX), abs(targetY - currY));
	}
	
	return ans;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
   	vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
   	
   	cout << minTimeToVisitAllPoints(points);
}

