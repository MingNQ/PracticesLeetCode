#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
	int m = grid.size(); 
	int n = grid[0].size();
	vector<int> oneRow(m, 0);
	vector<int> oneCol(n, 0);
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			oneRow[i] += grid[i][j];
			oneCol[j] += grid[i][j];
		}
	}
	
	vector<vector<int>> diff(m, vector<int>(n, 0));
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			diff[i][j] = 2 * oneRow[i] + 2 * oneCol[j] - m - n;
		}
	}        
	
	return diff;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int>> grid = {
		{0, 1, 1}, 
		{1, 0, 1}, 
		{0, 0, 1}
	};
	
	vector<vector<int>> diff = onesMinusZeros(grid);
	
	for(int i = 0; i < diff.size(); i++) {
		for(int j = 0; j < diff[i].size(); j++) {
			cout << diff[i][j] << " ";
		}
		cout << endl;
	}
}

