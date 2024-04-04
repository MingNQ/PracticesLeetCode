#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// C1 
//int numSpecial(vector<vector<int>>& mat) {
//	int count = 0;
//	int m = mat.size();
//	int n = mat[0].size();
//	vector<int> sum_row(m, 0);
//	vector<int> sum_col(n, 0);
//	
//	for(int i = 0; i < m; i++) {
//		for(int j = 0; j < n; j++) {
//			if (mat[i][j] == 1) {
//				sum_row[i]++;
//				sum_col[j]++;
//			}
//		}
//	}
//
//	for(int i = 0; i < mat.size(); i++) {
//		for(int j = 0; j < mat[i].size(); j++) {
//			if (mat[i][j] == 1 && sum_col[j] == 1 && sum_row[i] == 1) count++;
//		}
//	}        
//	return count;
//}

int numSpecial(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	
	int res = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (mat[i][j] == 0) continue;
			
			bool good = true;
			
			for(int r = 0; r < m; r++) {
				if (r != i && mat[r][j] == 1) {
					good = false;
					break;
				}
			}
			
			for(int c = 0; c < n; c++) {
				if (c != j && mat[i][c] == 1) {
					good = false;
					break;
				}
			}
			
			if (good) {
				res++;
			}
		}
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int>> mat = {
		{1, 0, 0},
		{0, 1, 0}, 
		{0, 0, 1}
	};
	
	cout << numSpecial(mat);
}

