#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int res = 0;
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] != 0 && i > 0) {
				matrix[i][j] += matrix[i - 1][j];
			}
		}
		
		vector<int> currRow = matrix[i];
		sort(currRow.begin(), currRow.end(), greater());
		
		for(int k = 0; k < n; k++) {
			res = max(res, currRow[i] * (i + 1));
		}
	} 
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

