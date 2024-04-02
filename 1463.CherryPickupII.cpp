#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int dp[71][71][71];

int helper(vector<vector<int>>& grid, int currRow, int robotACol, int robotBCol) {
	if (robotACol < 0 || robotBCol < 0 || robotACol >= grid[0].size() || robotBCol >= grid[0].size())
		return 0;
	if (currRow == grid.size()) 
		return 0;
	
	if (dp[currRow][robotACol][robotBCol] != -1)
		return dp[currRow][robotACol][robotBCol];
	
	int res = 0;
	
	res += grid[currRow][robotACol];
	res += grid[currRow][robotBCol];
	
	int maxRes = 0;
	
	for(int i = robotACol - 1; i <= robotACol + 1; i++) {
		for(int j = robotBCol - 1; j <= robotBCol + 1; j++) {
			if (i < j) 
				maxRes = max(maxRes, helper(grid, currRow + 1, i, j));
		}
	}
	
	res += maxRes;
	
	return dp[currRow][robotACol][robotBCol] = res;
}

int cherryPickup(vector<vector<int>>& grid) {
	int rows = grid.size();
	int cols = grid[0].size();
	memset(dp, -1, sizeof dp);
	
	return helper(grid, 0, 0, cols - 1);
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    
    cout << cherryPickup(grid);
}

